/*
 * File:   LCD_Libreria.c
 * Author: Victor Huatuco
 *
 * Created on 4 de febrero de 2021, 04:41 PM
 */


#include <xc.h>
#include "LCD_Libreria.h"
#include "Configuracion.h"
void LCD_Init(void) {
    
    LCD_PORT &= 0xf0;//clear port
    LCD_TRIS &= 0xf0;//clear tris
    RW_TRIS = 0;
    RS_TRIS = 0;
    E_TRIS = 0;
    
    RW_PIN = 0;
    RS_PIN = 0;
    E_PIN = 0;
    __delay_ms(15); //Segun datasheet
    
    LCD_Comando(0x30);
    __delay_ms(5);
    LCD_Comando(0x30);
    __delay_us(100);
    LCD_Comando(0x32);
    __delay_us(100);
    LCD_Comando(0x28);
    __delay_us(100);
    LCD_Comando(0x08);
    __delay_us(100);
    LCD_Comando(0x0f);
    __delay_us(100);
    LCD_Comando(0x01);
    __delay_us(100);
    LCD_Comando(0x04);
    __delay_us(100);
    
    __delay_us(100);
    LCD_Comando(0x06);
    LCD_Comando(0x0C);
    return;
}

void LCD_Comando(unsigned char cmd){
    LCD_PORT &= 0xf0;//clear port
    LCD_TRIS &= 0xf0;//clear tris
    LCD_PORT = LCD_PORT | ((cmd>>4)&0x0f);
    RW_PIN = 0;
    RS_PIN = 0;
    __delay_us(5);
    E_PIN = 1;
    __delay_us(5);
    E_PIN = 0;
    
    
    LCD_PORT &= 0xf0;
    LCD_PORT |= cmd&0x0f;
    __delay_us(5);
    E_PIN = 1;
    __delay_us(5);
    E_PIN = 0;
    
    LCD_TRIS |= 0x0f;  
    return;
}

void LCD_XY(int x, int y){
    if(x>0){
        LCD_Comando(0xC0+y);
    }
    else{
        LCD_Comando(0x80+y);
    }
    
}

void LCD_Cadena(const char *dato){
    while(*dato){
        __delay_us(100);
        LCD_Data(*dato);
        dato++;
    }
    
}

void LCD_Data(char data){
    __delay_us(100);
    LCD_PORT &= 0xf0;//clear port
    LCD_TRIS &= 0xf0;//clear tris
    
    LCD_PORT |= ((data>>4)&0x0f);
    RW_PIN = 0;
    RS_PIN = 1;
    __delay_us(5);
    E_PIN = 1;
    __delay_us(5);
    E_PIN = 0;
    
    LCD_PORT &= 0xf0;
    LCD_PORT |= (data&0x0f);
    
    __delay_us(5);
    E_PIN = 1;
    __delay_us(5);
    E_PIN = 0;
    LCD_TRIS |= 0x0f;
    return;
}