/*
 * File:   Programa_principal.c
 * Author: Victor Huatuco
 *
 * Created on 3 de febrero de 2021, 02:18 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"
void main(void) {
    LCD_Init();
    while(1){
        LCD_XY(0,0);
        LCD_Cadena("Salio");
        __delay_ms(100);
        LCD_XY(0,5);
        LCD_Cadena("XD");
        __delay_ms(100);
    } 
    return;
}
