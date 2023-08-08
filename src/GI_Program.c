/*
 * GI_Program.c
 *
 * Created: 12/23/2022 2:18:16 AM
 *  Author: Dell
 */ 
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/GI/GI_Private.h"
void MGI_voidEnable()
{
	SET_BIT(SREG,INTERRUPT_ENABLE_BIT);
}
void MGI_voidDisble()
{
	CLR_BIT(SREG,INTERRUPT_ENABLE_BIT);
}