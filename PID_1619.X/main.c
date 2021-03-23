/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1619
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

unsigned int codigo;
float salida;

unsigned int contador = 0;
float frecuencia;
char texto[40];
char flag_cero = 0;

float kp = 80; ki = 6 ; kd = 0.2 ; 
float error; up; ui; ui_ ; error_; ud; ut;
float set_point= 0.0;
float PID(float pid_in);


float PID(float pid_in) {  //pid_in es el valor del sensor del loop convertida a la magnitud de la variable
        
        const float max = 1023;
        const float min = 0;
        const float t_muestreo = 0.1;
        error = set_point - pid_in;
        up = kp*error;
        ui = ui_ + (ki * t_muestreo*error);
        ud = kd * (error - error_)/t_muestreo;
        ut = up + ui + ud; // es la salida del PID
        if (ut > max) ut=max;
        if (ut > min) ut=min;
        ui_ = ui;
        error_ = error;
        return ut;
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    printf("Iniciando\r\n");
    while (1)
    {
        // Add your application code
        codigo = ADC_GetConversion(0);
        set_point = 0.0635*codigo + 5.0;
        PWM3_LoadDutyValue(codigo);
        if (flag_cero != 0) frecuencia = (10000000)/(8.0*contador*4.0);
        
        flag_cero = 0;
        //sprintf(texto, "frec=%.2f\r\n", frecuencia);
       // printf(texto);
        //__delay_ms(500);
        PID(frecuencia);
        salida = ut;
        PWM3_LoadDutyValue(salida);
        sprintf(texto, "SP=%.2f/RPM=%.2F/\r\n", set_point,frecuencia,salida);
       printf(texto);
       __delay_ms(60);
        
    }
}
/**
 End of File
*/