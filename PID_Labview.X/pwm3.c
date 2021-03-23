   
 #include <xc.h>
 #include "pwm3.h"


 void PWM3_Initialize(void)
 {
    // Set the PWM to the options selected in the PIC10 / PIC12 / PIC16 / PIC18 MCUs.
    // PWM3POL active_hi; PWM3EN enabled; 
    PWM3CON = 0x80;   

    // DC 0; 
    PWM3DCH = 0x00;   

    // DC 0; 
    PWM3DCL = 0x00;   

    // Select timer
    CCPTMRSbits.P3TSEL = 0;
 }

 void PWM3_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM3DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM3DCL = (dutyValue & 0x0003)<<6;
 }
 /**
  End of File
 */
