/*
 * File:   main.c
 * Author: Victor Huatuco
 *
 * Created on March 22, 2021, 4:15 PM
 */


#include <xc.h>
#include <stdint.h>
#include "interrupt_manager.h"
#include "pwm3.h"
#include "tmr1.h"
#include "ext_int.h"
#include "tmr2.h"
#include "adc.h"
#include "eusart.h"


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



void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TRISAbits.RA0 = 1;
    TRISBbits.RB0 = 1;
    TRISBbits.RC0 = 0;
    
    

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
