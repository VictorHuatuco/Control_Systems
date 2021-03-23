
#ifndef TMR1_H
#define TMR1_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


void TMR1_Initialize(void);


void TMR1_StartTimer(void);


void TMR1_StopTimer(void);


uint16_t TMR1_ReadTimer(void);


void TMR1_WriteTimer(uint16_t timerVal);


void TMR1_Reload(void);


void TMR1_StartSinglePulseAcquisition(void);


uint8_t TMR1_CheckGateValueStatus(void);


bool TMR1_HasOverflowOccured(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR1_H
/**
 End of File
*/
