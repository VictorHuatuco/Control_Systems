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
#include "USART_libreria.h"
#include "ADC_libreria.h"
#include "LCD_Libreria.h"
unsigned int VTemp;
float temperatura;
char valor;
char datos[20];
void main(void) {

    TRISBbits.RB0 = 0;
    TRISAbits.RA0 = 1;
    TRISAbits.RA0 = 1;
    LCD_Init();
    ADC_init();
    USART_Init(9600);
    LCD_XY(0,0);
    LCD_Cadena("Temp:");
    while(1){
        VTemp = ADC_read(0);
        temperatura = VTemp;
        sprintf(datos,"%.2f",temperatura);
        LCD_XY(0,6);
        LCD_Cadena(datos);
        USART_Cadena("no :C");
       // USART_Tx(VTemp);
__delay_ms(100);
        //sprintf(texto,"%d",pulsos);
//        LCD_XY(0,0);
//        LCD_Cadena(texto);
        //valor = USART_Rx();
      if( valor == 'a'){LATBbits.LATB0 = 1;};
      if( valor == 'b'){LATBbits.LATB0 = 0;};
      //  else{ USART_Cadena("no :C");}
    }
    return;
}
