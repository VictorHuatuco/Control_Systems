/*
 * File:   Programa_principal.c
 * Author: Victor Huatuco
 *
 * Created on 4 de febrero de 2021, 04:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"
#define IO_encoder_A TRISCbits.RC0
#define IO_encoder_B TRISCbits.RC1
#define encoder_A PORTCbits.RC0
#define encoder_B PORTCbits.RC1

signed int pulsos = 0; //# de pulsos del encoder
char bit_actual; //bits actuales de A y B
char bit_anterior; //bits anteriores de A y B
char bit_armado; //Juntar actual y anterior
char texto[4];

void main(void) {
    LCD_Init();
    IO_encoder_A = 1;
    IO_encoder_B = 1;
    while(1){
    bit_actual = (encoder_A<<1) | encoder_B;
    bit_armado = (bit_anterior<<2) | bit_actual;
    
    if((bit_armado == 13) || (bit_armado == 4) || (bit_armado == 2) || (bit_armado == 11)) pulsos++;
    if((bit_armado == 14) || (bit_armado == 7) || (bit_armado == 1) || (bit_armado == 8)) pulsos--;
    sprintf(texto,"%d",pulsos);
    LCD_XY(0,0);
        LCD_Cadena(texto);


        bit_anterior = bit_actual;
    } 
    return;
}
