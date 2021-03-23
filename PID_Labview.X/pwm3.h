 /**
   PWM3 Generated Driver API Header File
 
   @Company
     Microchip Technology Inc. 

   @File Name
    pwm3.h

   @Summary
     This is the generated header file for the PWM3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This header file provides APIs for driver for PWM3.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
         Device            :  PIC16F1619
         Driver Version    :  2.01
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.31 and above or later
         MPLAB             :  MPLAB X 5.45
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

#ifndef PWM3_H
 #define PWM3_H
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include <stdint.h>

 #ifdef __cplusplus  // Provide C++ Compatibility

     extern "C" {

 #endif


 #define PWM3_INITIALIZE_DUTY_VALUE    0

 void PWM3_Initialize(void);

 void PWM3_LoadDutyValue(uint16_t dutyValue);

 
 #ifdef __cplusplus  // Provide C++ Compatibility

     }

 #endif

 #endif	//PWM3_H
 /**
  End of File
 */