/*
 * TIMERS_Program.c
 *
 * Created: 5/1/2023 1:00:57 PM
 *  Author: Muns
 */ 

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/TIMERS/TIMERS_Private.h"
#include "../Include/MCAL/TIMERS/TIMERS_Cfg.h"
#include "../Include/MCAL/TIMERS/TIMERS_Interface.h"

#define NULL 0

void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;
void (*TIMER1_ICU_CALLBACK)(void) = NULL;

void MTIMER0_voidinit(void)
{
	#if TIMER0_MODE == NORMAL

		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		
		//turn on overflow interrupt
		SET_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);
		//Timer0 pre_scaler
		TCCR0 &= 0b11111000;
		TCCR0 |= TIMER0_CLK_CFG;
		
		
	
	#elif TIMER0_MODE == PHASE_CORRECT
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);
		
		OCR0 = OCR0_VALUE;
		
		TCCR0 &= ~(3 << 4);
		TCCR0 |= TIMER0_PHASE_CORRECT_MODE << 4;
		
		TCCR0 &= ~(7);
		TCCR0 |= TIMER0_CLK_CFG;
	
	#elif TIMER0_MODE == CTC
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		
		SET_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);
		
		OCR0 = OCR0_VALUE;
		
		TCCR0 &= ~(3 << 4);
		TCCR0 |= TIMER0_CTC_OUTPUT_MODE << 4;
		
		TCCR0 &= 0b11111000;
		TCCR0 |= TIMER0_CLK_CFG;
		
	#elif TIMER0_MODE == PWM
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);
		
		OCR0 = OCR0_VALUE;
		
		TCCR0 &= ~(3 << 4);
		TCCR0 |= TIMER0_PWM_MODE << 4;
		
		TCCR0 &= ~(7);
		TCCR0 |= TIMER0_CLK_CFG;
	#endif
	
}

void MTIMER0_voidStopTimer(void)
{
	TCCR0 &= 0b11111000;
}
void MTIMER0_voidSetPreloadvalue(const u8 A_u8PreloadValue)
{
	TCNT0 = A_u8PreloadValue;
}
void MTIMER0_voidSetOcr0Value(const u8 A_u8Ocr0Value)
{
	OCR0 = A_u8Ocr0Value;
}

void MTIMER0_voidSetOvfCallback(void (*ptrToFunction)(void))
{
	if (ptrToFunction != NULL)
	{
		TIMER0_OVF_CALLBACK = ptrToFunction;
	}
}

void MTIMER0_voidSetCtcCallback(void (*ptrToFunction)(void))
{
	if (ptrToFunction != NULL)
	    TIMER0_CTC_CALLBACK = ptrToFunction;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL )
	{
		TIMER0_OVF_CALLBACK();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL )
	{
		TIMER0_CTC_CALLBACK();
	}
}

/////////////////////////////////////////
void MTIMER1_voidinit(void)
{
	//select timer1 mode---> 14
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	//select hw action on oc1A
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	//select hw action on oc1B
	CLR_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
	
	//select top value at icr1
	//ICR1 = TIMER1_ICR1_VALUE;
	
	OCR1A = OCR1A_VALUE;
	OCR1B = OCR1B_VALUE;
	
	#if TIMER1_ICU_ENABLE
		if (TIMER1_ICU_EDGE_SELECT)
		{
			SET_BIT(TCCR1B,6);
		}
		else
		{
			CLR_BIT(TCCR1B,6);
		}
		SET_BIT(TIMSK,5);
	#endif
	
	TCCR1B &= ~(7);
	TCCR1B |= TIMER1_CLK_CFG;
	
	
}

void MTIMER1_voidSetOcr1aValue(const u16 A_u8Ocr1aValue)
{
	OCR1A = A_u8Ocr1aValue;
}
void MTIMER1_voidSetOcr1bValue(const u16 A_u8Ocr1bValue)
{
	OCR1B = A_u8Ocr1bValue;
}

void MTIMER1_voidSetIcuEdgeSelect(const u8 A_u8IcuEdge)
{
	if (A_u8IcuEdge)
	{
		SET_BIT(TCCR1B,6);
	}
	else
	{
		CLR_BIT(TCCR1B,6);
	}
}
void MTIMER1_voidSetIcuCallback(void (*ptrToFunction)(void))
{
	if (ptrToFunction != NULL)
	{
		TIMER1_ICU_CALLBACK = ptrToFunction;
	}
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if (TIMER1_ICU_CALLBACK != NULL )
	{
		TIMER1_ICU_CALLBACK();
	}
}