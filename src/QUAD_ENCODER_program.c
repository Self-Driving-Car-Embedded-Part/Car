/*
 * QUAD_ENCODER_program.c
 *
 * Created: 5/13/2023 5:02:46 PM
 *  Author: MUNS
 */ 
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/HAL/QUAD_ENCODER/QUAD_ENCODER_Interface.h"
#include "../include/HAL/QUAD_ENCODER/QUAD_ENCODER_Cfg.h"



 
s32 velocityCount  = 0;
s32 positionCount  = 0;
u8 carDirection ='f';

void channel_A_VelocityRoutine(){
//	if(!MDIO_u8GetPinValue(DIO_PORTA,PIN2))
	if(MDIO_u8GetPinValue(DIO_PORTD,0))
	{
		carDirection = 'b';
		velocityCount--;
	}
	else
	{
		carDirection = 'f';
		velocityCount++;
	}
}
/*void channel_B_VelocityRoutine(){
	
	//MDIO_voidTogglePin(DIO_PORTA,PIN2);

	if(MDIO_u8GetPinValue(DIO_PORTD,6))
	{
		carDirection = 'f';
		velocityCount++;
	}
	else
	{
		carDirection = 'b';
		velocityCount--;
	}
}*/
void channel_A_PositionRoutine(){
	if(MDIO_u8GetPinValue(DIO_PORTD,1))
	{
			positionCount--;
	}
	
	else
	{
			positionCount++;
	}
}

s32 HQUADEn_s32getVelocityCount()
{
	return velocityCount;
}
s32 HQUADEn_s32getPositionCount()
{
	return positionCount;
}
u8 HQUADEN_u8getCarDirection()
{
	return carDirection;
}
void HQUADEn_voidResetVelocityCount() 
{
	velocityCount = 0;
}
void HQUADEn_voidResetPositionCount() 
{
	positionCount = 0;
}
u8 getCarDirection()
{
	return carDirection;
}
/************************************************************************/
/* you should set PIN_2 at port_D and PIN_6 Port_D as PULLDOWN                                                                      */
/************************************************************************/
void HQUADEN_voidinitVelocityEncoder()
{
	MEXTI_voidSetCfg(EXTI0,RISING_EDGE);
	//MTIMER1_voidSetIcuCallback(channel_A_VelocityRoutine);
	MEXTI_voidSetCallback(EXTI0,channel_A_VelocityRoutine);
	//MTIMER0_voidSetCtcCallback(calcVelocityAndPosition);
	
}
/************************************************************************/
/* you should set PIN_3 at port_D and PIN_2 Port_B as input                                                                      */
/************************************************************************/
void HQUADEN_voidinitPositionEncoder(){
	MEXTI_voidSetCfg(EXTI1,RISING_EDGE);
	MEXTI_voidSetCallback(EXTI1,channel_A_PositionRoutine);
	/*MEXTI_voidSetCfg(EXTI2,RISING_EDGE);
	MEXTI_voidSetCallback(EXTI2,channel_B_PositionRoutine);*/
}
