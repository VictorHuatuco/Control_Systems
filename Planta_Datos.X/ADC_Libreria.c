/*
 * File:   ADC_Libreria.c
 * Author: Victor Huatuco
 *
 * Created on 18 de febrero de 2021, 05:01 AM
 */


#include <xc.h>
#include "ADC_libreria.h"

void ADC_init(void) {
    ADCON1bits.PCFG = 1101;
    ADCON1bits.VCFG = 0;
    ADCON0 = 0;
    ADCON2bits.ACQT = 3;
    ADCON2bits.ADCS = 5;
    ADCON2bits.ADFM = 1;
    }
unsigned int ADC_read (unsigned char ch){
    if(ch > 13)return 0;
    ADCON0 = 0;
    ADCON0 = (ch<<2);
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE == 1);
    ADCON0bits.ADON = 0;
    return ADRES;       
}