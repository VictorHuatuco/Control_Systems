
#ifndef _EXT_INT_H
#define _EXT_INT_H

/**
    Section: Includes
*/
#include <xc.h>

// Provide C++ Compatibility
#ifdef __cplusplus  

extern "C" {

#endif


#define EXT_INT_InterruptFlagClear()       (INTCONbits.INTF = 0)


#define EXT_INT_InterruptDisable()     (INTCONbits.INTE = 0)


#define EXT_INT_InterruptEnable()       (INTCONbits.INTE = 1)


#define EXT_INT_risingEdgeSet()          (OPTION_REGbits.INTEDG = 1)


#define EXT_INT_fallingEdgeSet()          (OPTION_REGbits.INTEDG = 0)

void EXT_INT_Initialize(void);


void INT_ISR(void);


void INT_CallBack(void);


void INT_SetInterruptHandler(void (* InterruptHandler)(void));


extern void (*INT_InterruptHandler)(void);


void INT_DefaultInterruptHandler(void);

// Provide C++ Compatibility
#ifdef __cplusplus  

}

#endif
#endif
