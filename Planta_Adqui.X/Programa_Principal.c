/*
 * File:   Programa_Principal.c
 * Author: Victor Huatuco
 *
 * Created on 16 de febrero de 2021, 03:34 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "USART_libreria.h"

void main(void) {
    char valor;
    TRISDbits.RD0 = 0;
    TRISAbits.RA0 = 1;
    TRISAbits.RA0 = 1;
    ADCON1bits.PCFG = 1101;
    USART_Init(9600);
    
    while(1){
        
        valor = USART_Rx();
        if( valor == 'a'){LATDbits.LATD0 = 1;};
        if( valor == 'b'){LATDbits.LATD0 = 0;};
      //  else{ USART_Cadena("no :C");}
    
    //__delay_ms(500);

    }
    return;
}
