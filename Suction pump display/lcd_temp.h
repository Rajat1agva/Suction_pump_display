/*
 * lcd_temp.h
 *
 * Created: 9/27/2021 2:50:19 PM
 *  Author: agva
 */ 


#ifndef LCD_TEMP_H_
#define LCD_TEMP_H_

#ifndef text_tft_H
#define text_tft_H



#include "_font8x8.h"
#include "graphics_hex.c"
#include "font_17x27.h"
#include "font_11x15.h"
#include "SPI_0_AVR128DA64.h"
#include <math.h>
#include <avr/io.h>

#define LEFT 0
#define RIGHT 9999
#define CENTER 9998
#define swap(a, b) { int16_t t = a; a = b; b = t; }

/************************* colors byte ************************/
#define BLACK          0x0000      /*   0,   0,   0 */
#define WHITE          0xFFFF      /* 255, 255, 255 */
#define BLUE           0x001F      /*   0,   0, 255 */
#define GREEN          0x07E0      /*   0, 255,   0 */
#define RED            0xF800      /* 255,   0,   0 */
#define NAVY           0x000F      /*   0,   0, 128 */
#define DARKBLUE       0x0011      /*   0,   0, 139 */
#define DARKGREEN      0x03E0      /*   0, 128,   0 */
#define DARKCYAN       0x03EF      /*   0, 128, 128 */
#define CYAN           0x07FF      /*   0, 255, 255 */
#define TURQUOISE      0x471A      /*  64, 224, 208 */
#define INDIGO         0x4810      /*  75,   0, 130 */
#define DARKRED        0x8000      /* 128,   0,   0 */
#define OLIVE          0x7BE0      /* 128, 128,   0 */

#define GREY           0x8410      /* 128, 128, 128 */
#define SKYBLUE        0x867D      /* 135, 206, 235 */
#define BLUEVIOLET     0x895C      /* 138,  43, 226 */
#define LIGHTGREEN     0x9772      /* 144, 238, 144 */
#define DARKVIOLET     0x901A      /* 148,   0, 211 */
#define YELLOWGREEN    0x9E66      /* 154, 205,  50 */
#define BROWN          0xA145      /* 165,  42,  42 */
#define DARKGRAY       0x7BEF      /* 128, 128, 128 */
#define DARKGREY       0x7BEF      /* 128, 128, 128 */
#define SIENNA         0xA285      /* 160,  82,  45 */
#define LIGHTBLUE      0xAEDC      /* 172, 216, 230 */
#define GREENYELLOW    0xAFE5      /* 173, 255,  47 */
#define COLOR_SILVER         0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTGRAY      0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTGREY      0xC618      /* 192, 192, 192 */
#define COLOR_LIGHTCYAN      0xE7FF      /* 224, 255, 255 */
#define COLOR_VIOLET         0xEC1D      /* 238, 130, 238 */
#define COLOR_AZUR           0xF7FF      /* 240, 255, 255 */
#define COLOR_BEIGE          0xF7BB      /* 245, 245, 220 */
#define COLOR_MAGENTA        0xF81F      /* 255,   0, 255 */
#define COLOR_TOMATO         0xFB08      /* 255,  99,  71 */
#define COLOR_GOLD           0xFEA0      /* 255, 215,   0 */
#define COLOR_ORANGE         0xFD20      /* 255, 165,   0 */
#define COLOR_SNOW           0xFFDF      /* 255, 250, 250 */
#define COLOR_YELLOW         0xFFE0      /* 255, 255,   0 */
#define HOT_PINK             0xFF69     /* 255, 105,   180 */
/******************************************************************/

#define _digit	0x01
#define _alpha	0x02
#define  size_p 2
#define BG_COLOR BLACK
#define TXT_COLOR WHITE
#define sm 1
#define lg 0
#define MAX_PRESSURE  30
#define MIN_PRESSURE  25
#define font_1	0x00
#define font_2	0x01
#define font_3	0x02
#define background_color BLACK
///After changing pins here also do change in InitDisplay() function//

#define RS_PORT	PORTC
#define RS_PIN	PIN4_bm

#define RESET_PORT PORTC
#define RESET_PIN	PIN6_bm

#define CS_PORT	PORTA
#define CS_PIN	PIN7_bm

#define MOSI_PORT	PORTA
#define MOSI_PIN	PIN4_bm

#define SCK_PORT	PORTA
#define SCK_PIN		PIN6_bm



uint8_t line,size = 3;
char str_tmp[2];
unsigned int x=0,y=0;		//X AXIS AND Y AXIS
int ascii_vle=1;
char buff[50];
int set_pressure = MIN_PRESSURE,crrnt_pssre = MIN_PRESSURE;
uint8_t Hours = 0 ;
uint16_t rotation,width,height,HEIGHT,WIDTH;

/************************************* FUNCTION DECLARATION *********************************************************/

void Lcd_Write_Com(unsigned char VH);
void Lcd_Writ_Bus(unsigned char d);
void Lcd_Write_Data(unsigned int VH);
void Lcd_Write_Com_Data(unsigned char com,unsigned int dat);
unsigned char spi_tranceiver(unsigned char d);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void InitDisplay();
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void Rect(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c);
void Rectf(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c);
int RGB(int r,int g,int b);
void LCD_Clear(unsigned int j);
void Draw_Char(unsigned int x,unsigned int y, char * str_2_dsp, uint16_t color, uint8_t size);
void Draw_Pixel(int16_t x, int16_t y, uint16_t color);
void Draw_String( unsigned int x,unsigned int y,char * str_2_dsp, uint16_t color, uint8_t size,uint16_t BG);
void delchar(char *x,int a, int b);
void Fill_Rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void set_font(uint8_t f);
void LETTR(int16_t w,int16_t h,int16_t x1,int16_t y1,const unsigned long *_digit_arry_snt_);
unsigned long * _select_arry_(unsigned int _digit_);
void check_digit(int16_t w,int16_t h,int16_t x,int16_t y, unsigned int pssr_vle);
void Draw_sm( unsigned int x,unsigned int y,char * str_2_dsp1, uint16_t color, uint8_t size,int16_t font_type);
void two_icon(void);
void lock_icon(void);
int intToStr(long x, char str[], int d);
void reverse(char* str, int len);
void square_icon(void);
void sine_icon(void);
void two_icon_18(void);
void two_icon_10(void);
void pressure_screen(int set_p_temp);
void Set_Rotation(uint8_t r);
/****************************************** SPI DATA TRANSFER ******************************************************************/


unsigned char spi_tranceiver(unsigned char d)
{
	SPI_0_send_char(d);							//TRANSFER BYTE TO LCD
}


/****************************** SPI DATA TRANSFER TO LCD ********************************/


void Lcd_Writ_Bus(unsigned char d)
{
	spi_tranceiver(d);
}


/***************************** LCD TRANSFER COMMAND BYTE FUNCTION **********************************************/


void Lcd_Write_Com(unsigned char VH)
{
	RS_PORT.OUTCLR = RS_PIN;				//LCD_RS=0;			//TRANSFER OF COMMAND BYTE WHEN RS IS LOW
	Lcd_Writ_Bus(VH>>8);
	Lcd_Writ_Bus(VH);
}


/**************************** LCD TRANSFER DATA BYTE FUNCTION ************************************/


void Lcd_Write_Data(unsigned int VH)
{
	RS_PORT.OUTSET =RS_PIN;				//LCD_RS=1;				//TRANSFER OF DATA BYTE WHEN RS IS HIGH
	Lcd_Writ_Bus(VH>>8);				//DATA REQUIRED TO LCD IS 16 BIT OR 2 BYTE SO 8BIT SHIFT IS USED
	Lcd_Writ_Bus(VH);
}


/****************************** LCD TRANSFER COMMAND AND DATA BYTE FUNCTION ****************************************/


void Lcd_Write_Com_Data(unsigned char com,unsigned int dat)
{
	Lcd_Write_Com(com);
	Lcd_Write_Data(dat);
}


/******************************************** ADDRESS SET TO PRINT COLORS/PIXELS ***************************************************/


void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
	
	
	Lcd_Write_Com_Data(0x36,x2);	//Horizontal Window Address - 1
	Lcd_Write_Com_Data(0x37,x1);	//Horizontal Window Address - 2
	Lcd_Write_Com_Data(0x38,y2);	//Vertical Window Address - 1
	Lcd_Write_Com_Data(0x39,y1);	//Vertical Window Address - 2
	Lcd_Write_Com_Data(0x20,x1);	//RAM Address Set 1
	Lcd_Write_Com_Data(0x21,y1);	//RAM Address Set 2
	Lcd_Write_Com(0x22);			//Write Data to GRAM W=1
	
	
}


/***************************** LCD TFT DISPLAY INITIALIZATION ******************************************/

void InitDisplay()
{
	
	PORTC.DIRSET |=(1<<6);					//PB4 - RESET PIN // PB3 - RS PIN
	PORTC_OUT |=(1<<6);
	PORTC.DIRSET |= (1<<4);							//PC6  FOR CS
	PORTC_OUT |=(1<<4);
	PORTA.DIRSET |=(1<<7);
	PORTA_OUT |=(1<<7);
	
	
	
	SPI_0_init();
	
	
	RESET_PORT.OUTSET = RESET_PIN;						//RESET PIN TO RESET LCD
	_delay_ms(5);
	RESET_PORT.OUTCLR = RESET_PIN;
	_delay_ms(15);
	RESET_PORT.OUTSET = RESET_PIN;
	_delay_ms(15);

	CS_PORT.OUTCLR = CS_PIN;						// CS	LOW TO ACTIVATE CLIENT FOR SPI COMM.

	Lcd_Write_Com_Data(0x01,0x011c);			// Driver Output Control
	Lcd_Write_Com_Data(0x02,0x0100);			// LCD AC Driving Control
	Lcd_Write_Com_Data(0x03,0x1030);			// Entry Mode
	Lcd_Write_Com_Data(0x08,0x0808);			// set BP and FP
	Lcd_Write_Com_Data(0x0B,0x1100);			// frame cycle
	Lcd_Write_Com_Data(0x0C,0x0000);			// RGB interface setting R0Ch=0x0110 for RGB 18Bit and R0Ch=0111for RGB16Bit
	Lcd_Write_Com_Data(0x0F,0x0F01);			// Set frame rate----0801
	_delay_ms(10);
	Lcd_Write_Com_Data(0x15,0x0000);			// set system interface
	Lcd_Write_Com_Data(0x20,0x0000);			// Set GRAM Address
	Lcd_Write_Com_Data(0x21,0x0000);			// Set GRAM Address
	//*************Power On sequence ****************//
	_delay_ms(50);								// Delay 50ms
	Lcd_Write_Com_Data(0x10,0x0800);			// Set SAP,DSTB,STB----0A00
	Lcd_Write_Com_Data(0x11,0x1F3F);			// Set APON,PON,AON,VCI1EN,VC----1038
	_delay_ms(50);								// Delay 50ms
	Lcd_Write_Com_Data(0x12,0x0121);			// Internal reference voltage= Vci;----1121
	Lcd_Write_Com_Data(0x13,0x006F);			// Set GVDD----0066
	Lcd_Write_Com_Data(0x14,0x4349);			// Set VCOMH/VCOML voltage----5F60
	//-------------- Set GRAM area -----------------//
	Lcd_Write_Com_Data(0x30,0x0000);
	Lcd_Write_Com_Data(0x31,0x00DB);
	Lcd_Write_Com_Data(0x32,0x0000);
	Lcd_Write_Com_Data(0x33,0x0000);
	Lcd_Write_Com_Data(0x34,0x00DB);
	Lcd_Write_Com_Data(0x35,0x0000);
	Lcd_Write_Com_Data(0x36,0x00AF);
	Lcd_Write_Com_Data(0x37,0x0000);
	Lcd_Write_Com_Data(0x38,0x00DB);
	Lcd_Write_Com_Data(0x39,0x0000);
	// ----------- Adjust the Gamma Curve ----------//
	Lcd_Write_Com_Data(0x50,0x0001);  //0400
	Lcd_Write_Com_Data(0x51,0x200B);  //060B
	Lcd_Write_Com_Data(0x52,0x0000);  //0C0A
	Lcd_Write_Com_Data(0x53,0x0404);  //0105
	Lcd_Write_Com_Data(0x54,0x0C0C);  //0A0C
	Lcd_Write_Com_Data(0x55,0x000C);  //0B06
	Lcd_Write_Com_Data(0x56,0x0101);  //0004
	Lcd_Write_Com_Data(0x57,0x0400);  //0501
	Lcd_Write_Com_Data(0x58,0x1108);  //0E00
	Lcd_Write_Com_Data(0x59,0x050C);  //000E
	_delay_ms(50);                                     // Delay 50ms
	Lcd_Write_Com_Data(0x07,0x1017);
	Lcd_Write_Com(0x22);
	Set_Rotation(0);
	
	CS_PORT.OUTSET = CS_PIN;			  // CS	HIGH TO STOP CLIENT FOR SPI COMM.
	
	size = 1;
	WIDTH = 176;
	HEIGHT = 220;
	
}
/***************************************  Set Rotation  ********************************************************/


void Set_Rotation(uint8_t r)
{
	int16_t bfa;
	int16_t vsp;
	int16_t sea;
	rotation = r & 3;           // just perform the operation ourselves on the protected variables
	width = (rotation & 1) ? HEIGHT : WIDTH;
	height = (rotation & 1) ? WIDTH : HEIGHT;
	CS_PORT.OUTCLR = CS_PIN;
	
	uint16_t val;
	switch(rotation)
	{
		case 0:
		val = 0x1030; //0 degree
		break;
		case 1:
		val = 0x1028; //90 degree
		break;
		case 2:
		val = 0x1000; //180 degree
		break;
		case 3:
		val = 0x1018; //270 degree
		break;
	}
	
	Lcd_Write_Com_Data(0x03, val);
	Address_set(0, 0, width - 1, height - 1);
	sea = 0;
	bfa = 0;
	vsp = 0;
	sea =HEIGHT - 1;
	Lcd_Write_Com_Data(0x32, 0);
	Lcd_Write_Com_Data(0x31, sea);
	Lcd_Write_Com_Data(0x33, vsp);
	
	
	CS_PORT.OUTSET = CS_PIN;
}

/*****************************  HORIZONTAL LINE ********************************************************/


void H_line(unsigned int x1, unsigned int y1, unsigned int l, unsigned int c)
{
	uint16_t x,y;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	unsigned int i,j;
	CS_PORT.OUTCLR = CS_PIN;				//	CS LOW TO START SPI TRANSFER
	Lcd_Write_Com(0x22);					//	WRITE MEMORY START
	l=l+x;									// TO FIND LAST X axis COORDIANTE X start + LENGTH
	Address_set(x,y,l,y);					// SET ADDRESS WHERE TO DRAW
	j=l*2;									//	ONLY TO MAKE PIXELS FILL ALL POITNS SO *2
	for(i=1;i<=j;i++)
	{
		Lcd_Write_Data(c);					// TRANSFER DATA BYTE TO LCD
	}										//AFTER EACH WRITE ADDRESS SHIFT BY 1 BYTE IN ILI9225 DRIVER
	
	CS_PORT.OUTSET = CS_PIN;				//CS HIGH TO STOP SPI TRANSFER
	
	
}


/****************************  VERTICAL LINE **********************************************************/


void V_line(unsigned int x1, unsigned int y1, unsigned int l, unsigned int c)
{
	uint16_t x,y;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	unsigned int i,j;					// Only used in for loop
	
	CS_PORT.OUTCLR = CS_PIN;			//CS LOW TO START SPI TRANSFER
	
	Lcd_Write_Com(0x22);				// WRITE MEMORY START
	
	l=l+y;								// TO FIND LAST Y axis COORDIANTE Y start + LENGTH
	Address_set(x,y,x,l);				// SET ADDRESS WHERE TO DRAW
	j=l*2;
	for(i=1;i<=j;i++)
	{
		Lcd_Write_Data(c);				// TRANSFER DATA BYTE TO LCD
	}									//AFTER EACH WRITE ADDRESS SHIFT BY 1 BYTE IN ILI9225 DRIVER
	
	CS_PORT.OUTSET = CS_PIN;			//CS HIGH TO STOP SPI TRANSFER
	
}

/**********************************  RECTANGLE  **************************************/


void Rect(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c)
{
	
	H_line(x  , y  , w, c);			//FIRST HORIZONATAL LINE
	H_line(x  , y+h, w, c);			//SECOND HORIZONATAL LINE
	V_line(x  , y  , h, c);			//FIRST VERTICAL LINE
	V_line(x+w, y  , h, c);			//SECOND VERTICAL LINE
	
}

/************************************ RETANGLE FULL WITH COLOR ****************************/
void Rectf(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c)
{
	
	unsigned int i;
	for(i=0;i<h;i++)
	{
		H_line(x  , y  , w, c);				///FIRST LINE OF RECTANGLE
		H_line(x  , y+i, w, c);				//INCREMENT Y VALUE TO DRAW LINES
	}
	
}

/**************************** RGB COLOR MIX *********************/

int RGB(int r,int g,int b)
{

	return r << 16 | g << 8 | b;			//FIND MIX COLOR VALUE
}

/*********************************** CLEAR FULL LCD *****************************************/

void LCD_Clear(unsigned int j)
{
	unsigned int i,m;				//i is used for width or x axis //m is used as a height or y axis
	CS_PORT.OUTCLR = CS_PIN;		//	CS LOW TO START SPI TRANSFER
	width = (rotation & 1) ? HEIGHT : WIDTH;
	height = (rotation & 1) ? WIDTH : HEIGHT;
	Address_set(0,0,width-1,height-1);		// we need to clear whole lcd
	
	for(i=0;i<WIDTH;i++)
	for(m=0;m<HEIGHT;m++)
	{
		Lcd_Write_Data(j);
	}
	CS_PORT.OUTSET = CS_PIN;		//CS HIGH TO STOP SPI TRANSFER
}

/******************************** CLEAR AREA **************************************/

void clear_area(int16_t a1,int16_t b1 , int16_t a2,int16_t b2, uint16_t color)
{
	
	unsigned int i,m;					//i is used for width or x axis //m is used as a height or y axis
	CS_PORT.OUTCLR = CS_PIN;			//CS
	
	uint16_t x1,x2,y1,y2;
	
	x1 = (rotation & 1) ? b1 : a1;
	y1 = (rotation & 1) ? a1 : b1;
	
	x2 = (rotation & 1) ? b2 : a2;
	y2 = (rotation & 1) ? a2 : b2;
	
	Address_set(x1,y1,x2,y2);			//desired area to clear
	for(i=0;i<x2;i++)
	for(m=0;m<y2;m++)
	{
		Lcd_Write_Data(color);
	}
	CS_PORT.OUTSET = CS_PIN;

}


/***************************** DELETE CHAR FROM STRING **********************************/

void delchar(char *x,int a, int b)
{
	
	
	if ((a+b-1) <= strlen(x))			//check value of a i.e. place to delete char + b i.e.  total number of char -1 is greater than string length to validate
	{
		strcpy(&x[b-1],&x[a+b-1]);		//copy and place value of string from a+b-1th element in string at b-1th element.
	}
	
}

/************************************* DRAW STRING - FONT 8X8 *************************************/



void Draw_String( unsigned int x1,unsigned int y1,char * str_2_dsp1, uint16_t color, uint8_t size,uint16_t BG)
{
	char  tmp_store[50];							//TEMPORARY CHAR ARRAY
	
	uint16_t x,y;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	
	
	for(int i=0;i<50;i++)						//Run loop for 50 i.e. length of tmp_store buffer
	{
		if(i>(strlen(str_2_dsp1)-1))
		{
			tmp_store[i]="\0";					//fill elements of  tmp_store buffer with null character
		}										//when required string length is smaller than 50 to avoid garbage value
		tmp_store[i] = str_2_dsp1[i];			//	else paste

	}
	
	
	memset(str_tmp, '\0', sizeof(str_tmp));			//set memory for str_tmp string
	
	if((x < 0) || (y < 0) || (x > WIDTH) || (y > HEIGHT))		//input x,y are not in range or invalid
	{
		return;
	}
	

	
	while(1)
	{
		

		strncpy(str_tmp,tmp_store,1);				//copy 1character of tmp_store to str_tmp
		
		delchar(tmp_store,1, 1);					// remove that character from tmp_store
		
		
		ascii_vle= strcmp(str_tmp , "\0" ) ;		//compare and get ascii value of each charater
		
		
		
		if(ascii_vle == 0)							// if all characters are sent to lcd and last bit i.e. NULL char left
		{
			
			return;
		}
		

		for (int8_t i=0; i<9; i++)			// font it 8x8 so i<9
		{
			uint8_t line;
			if (i == 8)						// if i==8 then make line = 0x0 to avoid garbage value print on lcd
			{
				line = 0x0;
			}
			else
			{
				line = pgm_read_byte(lcd_font1+((ascii_vle-32)*8)+i);			// read array data stored in flash memory and assign it to line
			}																	// (ascii_vle-32)*8 --> -32 says that array byte start with 32ascii value character and *8 for 8byte of each char
			for (int8_t j = 0; j<8; j++)
			{
				if (line & 0x1)
				{
					if(size==1)
					{
						Draw_Pixel(x+i, y+j, color);							//when size is 1 rectangle is not valid as only single bit is printed.
					}
					
					else
					{
						Fill_Rect(x+(i*size), y+(j*size), size, size, color);
					}
				}
				else
				{
					if(size==1)
					{
						Draw_Pixel(x+i, y+j, BLACK);
					}
					
					else
					{
						Fill_Rect(x+(i*size), y+(j*size), size, size, BLACK);
					}
				}
				
				line >>= 1;															//shift line 8bit data by 1 bit
			}
			
			
		}
		x += size*8;																//when 1 char is printed then shift x axis to 8 position( according to font size)
		

	}
	
}


/****************************************DRAW STRING - FONT 17 X 27 AND FONT 11 X 15 *********************************************/


void Draw_sm( unsigned int x,unsigned int y,char * str_2_dsp1, uint16_t color, uint8_t size,int16_t font_type)
{
	char  tmp_store[50] ;
	unsigned int y_temp = y,_char_type=0;
	//TEMPORARY CHAR ARRAY
	
	for(int i=0;i<50;i++)
	{
		if(i>(strlen(str_2_dsp1)-1))
		{
			tmp_store[i]="\0";
		}
		tmp_store[i] = str_2_dsp1[i];

	}
	
	
	memset(str_tmp, '\0', sizeof(str_tmp));
	
	if((x < 0) || (y < 0) || (x > 176) || (y > 220))
	{
		return;
	}
	

	
	while(1)
	{
		int16_t w,h;
		int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
		uint8_t byte = 0;


		strncpy(str_tmp,tmp_store,1);
		
		delchar(tmp_store,1, 1);
		
		
		ascii_vle= strcmp(str_tmp , "\0" ) ;
		
		
		if(ascii_vle == 0)
		{
			
			return;
		}
		
		if(ascii_vle >= 176)
		{
			ascii_vle++;
		}
		
		//FOR DIGITS ""lcd_font2[((ascii_vle-48)*54)+(j * byteWidth) + i / 8]""//
		//FOR ALPHA		""lcd_font_alpha[((ascii_vle-65)*78)+(j * byteWidth) + i / 8]""// TIMES NEW ROMAN
		if(font_type == font_1)
		{
			
			
			if(ascii_vle>=48 && ascii_vle<57)					//when digits  font size is different
			{
				_char_type = _digit;
				w=12,h=27;	//for digits w=12,h=27 //for alpha w = 17,h = 27
				byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
				byte = 0;
				
			}
			else
			{
				_char_type = _alpha;
				
				if(ascii_vle == 87||ascii_vle==77)					//for M and W size is different
				{
					w=23,h=27;	//for digits w=12,h=27 //for alpha w = 17,h = 27
					byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
					byte = 0;

				}
				else
				{
					w=17,h=27;	//for digits w=12,h=27 //for alpha w = 17,h = 27
					byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
					byte = 0;
				}
			}
		}
		else
		{
			w=11,h=15;
			byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
			byte = 0;
		}
		for (int16_t j = 0; j < h; j++, y_temp++)
		{
			for (int16_t i = 0; i < w; i++)
			{
				if (i & 7)
				{
					byte <<= 1;
				}

				else{
					switch (font_type)
					{
						case font_1:
						if(_char_type == _digit)
						{
							byte = pgm_read_byte(&lcd_font2[((ascii_vle-48)*54)+(j * byteWidth) + i / 8]);
						}
						else
						{
							byte = pgm_read_byte(&lcd_font_3[((ascii_vle-65)*81)+(j * byteWidth) + i / 8]);
						}
						
						break;
						case font_2:
						byte = pgm_read_byte(&lcd_font_4[((ascii_vle-32)*30)+(j * byteWidth) + i / 8]);
						break;
						default:
						break;
						
					}
				}
				if (byte & 0x80)
				{
					Draw_Pixel(x + i*size, y_temp,color);
				}
				else
				{
					
					Draw_Pixel(x + i*size, y_temp, background_color);
				}
				
			}
		}

		y_temp=y;
		if(font_type==font_2)
		{
			x += size*8;
		}
		else
		{
			x += size*14;
		}
	}
	
}


/********************************* DRAW SINGLE CHAR ***************************************/


void Draw_Char( unsigned int x,unsigned int y,char * str_2_dsp1, uint16_t color, uint8_t size)
{
	
	char  tmp_store[50] ;							//TEMPORARY CHAR ARRAY
	
	for(int i=0;i<strlen(str_2_dsp1);i++)
	{
		tmp_store[i] = str_2_dsp1[i];
	}
	
	
	memset(str_tmp, '\0', sizeof(str_tmp));
	
	if((x < 0) || (y < 0) || (x > 176) || (y > 220))
	{
		return;
	}
	
	strncpy(str_tmp,tmp_store,1);
	
	delchar(tmp_store,1, 1);
	
	
	ascii_vle= strcmp(str_tmp , "\0" ) ;
	
	
	if(ascii_vle >= 176)
	{
		ascii_vle++;
	}
	
	for (int8_t i=0; i<9; i++)
	{
		uint8_t line;
		if (i == 8)
		{
			line = 0x0;
		}
		else
		{
			line = pgm_read_byte(lcd_font1+((ascii_vle-32)*8)+i);
		}
		for (int8_t j = 0; j<8; j++)
		{
			if (line & 0x1)
			{
				if(size==1)
				{
					Draw_Pixel(x+i, y+j, color);
				}
				
				else
				{
					
					Fill_Rect(x+(i*size), y+(j*size), size, size, color);
				}
			}
			
			line >>= 1;
		}
		
		
	}
	x += size*8;
	
	
}


/************************** DRAW PIXELS *************************************/

void Draw_Pixel(int16_t x, int16_t y, uint16_t color)
{
	uint16_t x1,y1;
	
	x1 = (rotation & 1) ? y : x;
	y1 = (rotation & 1) ? x : y;
	
	
	if((x < 0) || (y < 0) || (x > WIDTH) || (y > HEIGHT))
	{
		return;
	}
	
	
	
	CS_PORT.OUTCLR = CS_PIN;				//CS
	Address_set(x1, y1, x1, y1);
	
	Lcd_Write_Com_Data(0x22,color);

	CS_PORT.OUTSET = CS_PIN;
	
}

/********************************** RECTANGLE FOR CHARS **********************************/

void Fill_Rect(int16_t x1, int16_t y1, int16_t w, int16_t h, uint16_t color)
{
	uint16_t x,y;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	
	int16_t end;
	if (w < 0)
	{
		w = -w;
		x -= w;
	}                           //+ve w
	end = x + w;
	if (x < 0)
	{
		x = 0;
	}
	if (end > 176)
	{
		end = 176;
	}
	w = end - x;
	if (h < 0)
	{
		h = -h;
		y -= h;
	}                           //+ve h
	end = y + h;
	if (y < 0)
	{
		y = 0;
	}
	if (end > 220)
	{
		end = 220;
	}
	
	h = end - y;
	CS_PORT.OUTCLR = CS_PIN;  //CS
	Address_set(x, y, x + w - 1, y + h - 1);
	
	
	Lcd_Write_Com(0x22);
	if (h > w)
	{
		end = h;
		h = w;
		w = end;
	}
	while (h-- > 0)
	{
		end = w;
		do
		{

			Lcd_Write_Data(color);
			
		} while (--end != 0);
	}

	CS_PORT.OUTSET = CS_PIN;
	
}


/********************************* CHECK DIGIT IS SINGLE OR DOUBLE *********************************************/


void check_digit(int16_t w,int16_t h,int16_t x1,int16_t y1,unsigned int pssr_vle)
{
	
	uint16_t x,y;
	
	
	
	const unsigned long *_digit_arry_chk_;
	if(pssr_vle<=9)
	{
		x = (rotation & 1) ? y1 : x1+w-7;
		y = (rotation & 1) ? x1+w-7 : y1;
		
		_digit_arry_chk_ = _select_arry_(pssr_vle);
		//LETTR(w, h,x+w-7, y,_digit_arry_chk_);
		LETTR(w, h,x, y,_digit_arry_chk_);
		_delay_ms(2);
		
		x = (rotation & 1) ? y1 : x1-2;
		y = (rotation & 1) ? x1-2 : y1;
		
		_digit_arry_chk_ = _select_arry_(0);
		//LETTR(w,h,x-2,y,_digit_arry_chk_);
		LETTR(w, h,x, y,_digit_arry_chk_);

	}
	else
	{
		for(int _digit_=0;_digit_<2;_digit_++)
		{
			x = (rotation & 1) ? y1 : x1-2;
			y = (rotation & 1) ? x1-2 : y1;
			_digit_arry_chk_ = _select_arry_(pssr_vle/10);
			//LETTR(w,h,x-2,y,_digit_arry_chk_);
			LETTR(w, h,x, y,_digit_arry_chk_);
			_delay_ms(5);
			
			x = (rotation & 1) ? y1 : x1+w-7;
			y = (rotation & 1) ? x1+w-7 : y1;
			_digit_arry_chk_ = _select_arry_(pssr_vle%10);
			//LETTR(w,h,x+w-7,y,_digit_arry_chk_);
			LETTR(w, h,x, y,_digit_arry_chk_);
		}
	}
}


/************************************************ SELECT DIGIT ARRAY FOR BIG DIGIT SIZE - 45 X 74 ******************************************************************/

unsigned long * _select_arry_(unsigned int _digit_)
{
	const unsigned long *_digit_arry_ ;
	switch(_digit_)
	{
		case 1:
		_digit_arry_ = _1_lttr;
		break;
		case 2:
		_digit_arry_ = _2_lttr;
		break;
		case 3:
		_digit_arry_ = _3_lttr;
		break;
		case 4:
		_digit_arry_ = _4_lttr;
		break;
		case 5:
		_digit_arry_ = _5_lttr;
		break;
		case 6:
		_digit_arry_ = _6_lttr;
		break;
		case 7:
		_digit_arry_ = _7_lttr;
		break;
		case 8:
		_digit_arry_ = _8_lttr;
		break;
		case 9:
		_digit_arry_ = _9_lttr;
		break;
		default:
		_digit_arry_ = _0_lttr;
		break;
	}
	return (unsigned long *)_digit_arry_;
	
}

/*************************************************** DRAW DIGIT FOR DIGITS 45 X 74 ***************************************************************************/

void LETTR(int16_t w,int16_t h,int16_t x1,int16_t y1,const unsigned long *_digit_arry_snt_)
{
	//int16_t w=45,h=74,x=25,y=50;
	uint16_t x,y;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	int16_t byteWidth = (w + 7) / 8;			//to avoid wastage of memory and also not left any bit of char
	uint8_t byte = 0;
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&_digit_arry_snt_[j * byteWidth + i / 8]);			//read byte from flash memory and i/8 used to find which byte is being used in array.
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			else
			{
				Draw_Pixel(x + i, y, BLACK);
			}
			
		}
	}
}



/****************************** PRESSURE SET SCREEN ***************************************/

void pressure_screen(int set_p_temp)
{
	
	
	sine_icon();
	LETTR(30,20,145,5,batt2);
	
	Draw_sm(5,5,"P", TXT_COLOR, 1,font_1);
	//clear_area(2,5,14,20,BG_COLOR);
	//_delay_ms(5);
	
	check_digit(45,74,22,57,set_p_temp);			//current pressure required big digit
	_delay_ms(2);

	Draw_sm(105,90,"cmH", TXT_COLOR, 1,font_1);
	two_icon_18();
	Draw_sm(156,90,"O", TXT_COLOR, 1,font_1);
	
	
}


/****************************************************** LOCK ICON FOR DISPLAY SIZE - 25 X 25*********************************************************************/

void lock_icon(void)
{
	
	
	
	
	
	int16_t w=25,h=25,x1=5,y1=5;
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&_lock_1[j * byteWidth + i / 8]);
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			
		}
	}
	clear_area(5,140,85,150,BG_COLOR);
}

/****************************************************** SQUARE ICON FOR DISPLAY SIZE - 25 X 25*********************************************************************/

void square_icon(void)
{
	
	
	int16_t w=25,h=25,x1=80,y1=5;
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&_square_icon[j * byteWidth + i / 8]);
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			
		}
	}
	
}

/****************************************************** SINE WAVE ICON FOR DISPLAY SIZE - 25 X 25*********************************************************************/

void sine_icon(void)
{

	
	int16_t w=25,h=19,x1=78,y1=5;
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&_sine_icon[j * byteWidth + i / 8]);
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			
		}
	}
}

/****************************************************** DIGIT 2 FOR DISPLAY SIZE - 9 X 20*********************************************************************/

void two_icon_18(void)
{
	int16_t w=9,h=20,x1=150,y1=95;
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
	
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&font_18[j * byteWidth + i / 8]);
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			
		}
	}
	clear_area(5,140,85,150,BG_COLOR);
}

/******************************************************  DIGIT 2 FOR DISPLAY SIZE - 5 X 12*********************************************************************/

void two_icon_10(void)
{
	int16_t w=5,h=12,x1=148,y1=192;
	int16_t byteWidth = (w + 7) / 8;
	uint8_t byte = 0;
	x = (rotation & 1) ? y1 : x1;
	y = (rotation & 1) ? x1 : y1;
	
	for (int16_t j = 0; j < h; j++, y++) {
		for (int16_t i = 0; i < w; i++) {
			if (i & 7)
			{
				byte <<= 1;
			}
			else
			{
				byte = pgm_read_byte(&font_10_2[j * byteWidth + i / 8]);
			}
			if (byte & 0x80)
			{
				Draw_Pixel(x + i, y, WHITE);
			}
			
		}
	}
	clear_area(5,140,85,150,BG_COLOR);
}

void drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color) {

	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	

	Draw_Pixel(x0, y0 + r, color);
	Draw_Pixel(x0, y0-  r, color);
	Draw_Pixel(x0 + r, y0, color);
	Draw_Pixel(x0 - r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		Draw_Pixel(x0 + x, y0 + y,color);
		Draw_Pixel(x0 - x, y0 + y,color);
		Draw_Pixel(x0 + x, y0 - y,color);
		Draw_Pixel(x0 - x, y0 - y,color);
		Draw_Pixel(x0 + y, y0 + x,color);
		Draw_Pixel(x0 - y, y0 + x,color);
		Draw_Pixel(x0 + y, y0 - x,color);
		Draw_Pixel(x0 - y, y0 - x,color);
	}
	
}
void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {

	// Classic Bresenham algorithm
	int16_t steep = abs((int16_t)(y2 - y1)) > abs((int16_t)(x2 - x1));

	int16_t dx, dy;

	if (steep) {
		uint16_t temp;
		temp= x1;
		x1=y1;
		y1=temp;
		temp=x2;
		x2=y2;
		y2=temp;
		//_swap(x1, y1);
		
		//_swap(x2, y2);
	}

	if (x1 > x2) {
		//_swap(x1, x2);
		uint16_t temp = x1;
		x1=x2;
		x2=temp;
		//_swap(y1, y2);
		temp = y1;
		y1 = y2;
		y2=temp;
		
	}

	dx = x2 - x1;
	dy = abs((int16_t)(y2 - y1));

	int16_t err = dx / 2;
	int16_t ystep;

	if (y1 < y2) ystep = 1;
	else ystep = -1;

	
	for (; x1<=x2; x1++) {
		if (steep) Draw_Pixel(y1, x1, color);
		else       Draw_Pixel(x1, y1, color);

		err -= dy;
		if (err < 0) {
			y1 += ystep;
			err += dx;
		}
	}
	
}
void fillCircle(uint8_t x0, uint8_t y0, uint8_t radius, uint16_t color) {

	int16_t f = 1 - radius;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * radius;
	int16_t x = 0;
	int16_t y = radius;

	
	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		drawLine(x0 + x, y0 + y, x0 - x, y0 + y, color); // bottom
		drawLine(x0 + x, y0 - y, x0 - x, y0 - y, color); // top
		drawLine(x0 + y, y0 - x, x0 + y, y0 + x, color); // right
		drawLine(x0 - y, y0 - x, x0 - y, y0 + x, color); // left
	}

	
}



void drawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color) {
	
	drawLine(x1, y1, x2, y2, color);
	drawLine(x2, y2, x3, y3, color);
	drawLine(x3, y3, x1, y1, color);
	
}
#endif










#endif /* LCD_TEMP_H_ */