/*
 * File:   Programa_Principal.c
 * Author: Victor Huatuco
 *
 * Created on 16 de febrero de 2021, 03:34 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "Configuracion.h"
#include "PID.h"

void main(void) {
    
    while(1){
        TRISBbits.RB7 = 0;
        LATBbits.LATB7 = ~LATBbits.LATB7;
    }
    return;
}
