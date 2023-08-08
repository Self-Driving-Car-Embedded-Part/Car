/*
 * CAR.c
 *
 * Created: 5/19/2023 6:51:33 AM
 *  Author: MUNSOUR
 */ 
#include "../include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/MCAL/TWI/TWI_Interface.h"
#include "../Include/HAL/QUAD_ENCODER/QUAD_ENCODER_Interface.h"
#include "../Include/CAR/CAR.h"

/**
it will use Timer1 ICU pin and INT0 PIN
i will count only the rising edge of both A and B channels
Speed (in RPM) = (Encoder Pulses per Second / PPR) x 60
where Encoder Pulses per Second = (Encoder Counts / Time Interval)
**/
/************************************************************************/
/*To convert RPM to m/s, you need to know the circumference of the rotating object, which is given by:

Circumference = 2 x ? x r

where r is the radius of the rotating object.

Once you know the circumference, you can convert RPM to m/s using the following formula:

m/s = (RPM x Circumference) / 60

Conversely, to convert m/s to RPM, you can use the following formula:

RPM = (m/s x 60) / Circumference                                                                      */
/************************************************************************/
/************************************************************************/
/* function name : set car
/* calling by TIMER0 interrupt every 10ms calculate the peed of the car
/* and compare it with the target and calculate PID values
/* and set the car speed and position
/* call encoder and PID functions inside isr
/* and also call car functions moveForword() & moveBackword() & setPosition();      
/*direction of the movement in encoder interface file u can use it as direction in car.c                                                        */
/************************************************************************/
//CAR Parameters


//Low Pass Filter Parameters
/*f32 prevOutput = 0.0;
f32 lowPassFilter(f32 value){}*/
/************************************************************************/
/* you can use MTIMER1_voidSetOcr1aValue(const u16 A_u8Ocr1aValue) function
/* in both moveForword & moveBackword function to set duty cycle (0 -> 1024)  
/* Assume the PINS of the speed encoder on PIN_A0 & PIN_A1                                                                   */
/************************************************************************/
u8 carState = 'S';
void setBackMotor(u16 duty,u8 direction)
{
	MTIMER1_voidSetOcr1aValue(duty & 0x03ff);
	if(direction == 'f')
	{
		MDIO_voidSetPinValue(DIO_PORTA,0,DIO_HIGH);
		MDIO_voidSetPinValue(DIO_PORTA,1,DIO_LOW);
	}
	else
	{
		MDIO_voidSetPinValue(DIO_PORTA,0,DIO_LOW);
		MDIO_voidSetPinValue(DIO_PORTA,1,DIO_HIGH);
	}
}

void setSteeringMotor(f32 v,f32 Vmax )
{
	f32 tmp = abs(v);
	s32 pwmVal = (s32)tmp;
	if(pwmVal > 255)
		pwmVal = 255;
	
		if(v > 0 )
		{
			MDIO_voidSetPinValue(DIO_PORTA,2,DIO_HIGH);
			MDIO_voidSetPinValue(DIO_PORTA,3,DIO_LOW);
		}
		else if(v < 0)
		{
			MDIO_voidSetPinValue(DIO_PORTA,2,DIO_LOW);
			MDIO_voidSetPinValue(DIO_PORTA,3,DIO_HIGH);
		}
		
	
		else
		{
			
			MDIO_voidSetPinValue(DIO_PORTA,2,DIO_LOW);
			MDIO_voidSetPinValue(DIO_PORTA,3,DIO_LOW);
		

		}
		MTIMER1_voidSetOcr1bValue(pwmVal);
	
	
}



void readACommandFromRasbperry(char* command){}
	
