
#ifndef EUSART_H
#define EUSART_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: Macro Declarations
*/

#define EUSART_DataReady  (EUSART_is_rx_ready())

/**
  Section: Data Type Definitions
*/

typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}eusart_status_t;



void EUSART_Initialize(void);


bool EUSART_is_tx_ready(void);


bool EUSART_is_rx_ready(void);


bool EUSART_is_tx_done(void);


eusart_status_t EUSART_get_last_status(void);


uint8_t EUSART_Read(void);


void EUSART_Write(uint8_t txData);




void EUSART_SetFramingErrorHandler(void (* interruptHandler)(void));


void EUSART_SetOverrunErrorHandler(void (* interruptHandler)(void));


void EUSART_SetErrorHandler(void (* interruptHandler)(void));



#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // EUSART_H
/**
 End of File
*/
