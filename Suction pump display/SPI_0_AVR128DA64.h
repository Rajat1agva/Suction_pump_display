#ifndef SPI_0_AVR128DA64_H_
#define SPI_0_AVR128DA64_H_

#define SlaveSelectDIR (PORTA_DIR |= (1 << 7))
#define SlaveSelectEnable (PORTA_OUT &= ~(1 << 7))
#define SlaveSelectDisable (PORTA_OUT |= (1 << 7))

/************************************************************************/
/* Initialization
Initialize the SPI to a basic functional state by following these steps:
1. Configure the SS pin in the port peripheral.
2. Select the SPI master/slave operation by writing the Master/Slave Select (MASTER) bit in the Control A
(SPIn.CTRLA) register.
3. In Master mode, select the clock speed by writing the Prescaler (PRESC) bits and the Clock Double (CLK2X)
bit in SPIn.CTRLA.
4. Optional: Select the Data Transfer mode by writing to the MODE bits in the Control B (SPIn.CTRLB) register.
5. Optional: Write the Data Order (DORD) bit in SPIn.CTRLA.
6. Optional: Set up the Buffer mode by writing the BUFEN and BUFWR bits in the Control B (SPIn.CTRLB)
register.
7. Optional: To disable the multi-master support in Master mode, write ?1? to the Slave Select Disable (SSD) bit in
SPIn.CTRLB.
8. Enable the SPI by writing a ?1? to the ENABLE bit in SPIn.CTRLA.                                                                     */
/************************************************************************/
void SPI_0_init(void)
{
	
	
	PORTA.DIR |= PIN4_bm; // MOSI channel
	PORTA.DIR &= ~PIN5_bm; // MISO channel
	PORTA.DIR |= PIN6_bm; // SCK channel
	PORTA.DIR |=PIN7_bm;
	PORTA.OUTSET = PIN7_bm;
	
	SPI0.CTRLA |= (1 << 5);    // SPI Master mode selected, CLK_PER/4.
	SPI0.CTRLA |= (1 << 0)|(1<<4);               // SPI enabled.
	
	
	
	
}

unsigned char SPI_0_send_char(unsigned char data)
{

	
	SPI0.DATA = data;
	while (!(SPI0.INTFLAGS & (1 << 7))) ;          // flag is set when a serial transfer is complete.
	return(SPI0.DATA);

}

void SPI_0_send_string(char *str)
{
	while(*str != '\0')
	{
		SPI_0_send_char(*str);
		str++;
	}
}

#endif