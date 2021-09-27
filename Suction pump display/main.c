/*
 
* Suction Pump.c
 
 * Created: 9/10/2021 11:15:51 AM
 
 * Author : RAJAT MISHRA
 
 * Hardware : ILI9225 t ft display module,avr128da48 micro controller
 
 */ 


/************************************/
#define F_CPU 24000000
#define PI 3.14
#define RADIUS  75

/***********************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/eeprom.h>
#include <avr/xmega.h>
#include <math.h>
#include "LCD_TFT.h"
#include "SPI_0_AVR128DA64.h"
#include "graphics_hex.c"

/***********************************/





int main(void)
{   
	
	_PROTECTED_WRITE (CLKCTRL.OSCHFCTRLA, ((CLKCTRL_FREQSEL_24M_gc)|(CLKCTRL_AUTOTUNE_bm)));  //Oscillator frequency is 24MHz // Auto tuning enabled
	sei();
	
    InitDisplay();      //Initialize TFT 
	LCD_Clear(BLACK);	//Set background black
	SPI_0_init();       //Initialize SPI
	Set_Rotation(0);
	
	LETTR(176,220,0,0,image1);
	drawCircle(110,110,10,WHITE);
	while (1) 
	{for(int i=45;i<=300;i++)
     {drawLine(110,110,110+50*cos(i*(PI/180)),110+50*sin(i*(PI/180)),WHITE);
	  drawLine(110,110,110+50*cos(i*(PI/180))+1,110+50*sin(i*(PI/180))+1,WHITE);
	    	
	  _delay_ms(10); 
	  drawLine(110,110,110+50*cos(i*(PI/180)),110+50*sin(i*(PI/180)),BLACK);
	   drawLine(110,110,110+50*cos(i*(PI/180))+1,110+50*sin(i*(PI/180))+1,BLACK);
	  
	   drawCircle(110,110,10,WHITE);
	   		 
	 }
	for(int i=300;i>=45;i--)
	{drawLine(110,110,110+50*cos(i*(PI/180)),110+50*sin(i*(PI/180)),WHITE);
		drawLine(110,110,110+50*cos(i*(PI/180))+1,110+50*sin(i*(PI/180))+1,WHITE);
		
		_delay_ms(10);
		drawLine(110,110,110+50*cos(i*(PI/180)),110+50*sin(i*(PI/180)),BLACK);
		drawLine(110,110,110+50*cos(i*(PI/180))+1,110+50*sin(i*(PI/180))+1,BLACK);
		
		drawCircle(110,110,10,WHITE);
	}
    }


}


		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 

		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 

