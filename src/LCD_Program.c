/*
 * LCD_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Dell
 */
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"


#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/LCD_Driver/LCD_Interface.h"
#include "../Include/HAL/LCD_Driver/LCD_Cfg.h"
#include "../Include/HAL/LCD_Driver/LCD_Private.h"

#include <avr/delay.h>
#include <math.h>


void HLCD_voidSendCommand(const u8 A_u8Command)
{
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(E_DELAY);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}
void HLCD_voidSendData(const u8 A_u8Data)
{
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(E_DELAY);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}


void HLCD_voidInit()
{
	_delay_ms(INIT_VDD_DELAY);
	HLCD_voidSendCommand(FUNCTION_SET);
	_delay_ms(1);
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);
	HLCD_voidSendCommand(DISPALY_CLEAR);
	_delay_ms(2);
	HLCD_voidSendCommand(ENTRY_MODE_SET);

}
void HLCD_voidClearDisplay()
{
	HLCD_voidSendCommand(DISPALY_CLEAR);
	_delay_ms(2);
}

void HLCD_voidSendString(const u8 *A_pu8String)
{
	while(*A_pu8String>0)
	{
		HLCD_voidSendData(*A_pu8String++);
	}
}

void HLCD_voidGoToPos (u8 A_u8RowNumber, u8 A_u8ColNumber)
{
	switch(A_u8RowNumber)
	{
	case ROW_ONE : HLCD_voidSendCommand(LCD_ROW_ONE + A_u8ColNumber); break;
	case ROW_TWO : HLCD_voidSendCommand(LCD_ROW_TWO + A_u8ColNumber); break;
	}
}
void HLCD_voidDisplayNumber (u32 A_u32Number)
{
	u32 local_u32Number = 1;
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	else
	{
		while (A_u32Number != 0)
		{
			local_u32Number = ((local_u32Number*10)+(A_u32Number%10));
			A_u32Number = A_u32Number / 10;
		}
		while (local_u32Number !=1)
		{
			HLCD_voidSendData((local_u32Number%10)+48);
			local_u32Number = local_u32Number /10;
		}
	}
}
