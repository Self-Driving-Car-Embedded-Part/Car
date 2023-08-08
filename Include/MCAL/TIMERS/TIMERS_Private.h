/*
 * TIMERS_Private.h
 *
 * Created: 5/1/2023 1:00:16 PM
 *  Author: Dell
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#define TCCR0	(*((volatile u8 *)0x53))
#define TCNT0	(*((volatile u8 *)0x52))
#define OCR0	(*((volatile u8 *)0x5c))

#define TCCR1A	(*((volatile u8 *)0x4F))
#define TCCR1B	(*((volatile u8 *)0x4E))
#define TCNT1	(*((volatile u16 *)0x4C))
#define OCR1A	(*((volatile u16 *)0x4A))
#define OCR1B	(*((volatile u16 *)0x48))
#define ICR1	(*((volatile u16 *)0x46))


#define TIMSK	(*((volatile u8 *)0x59))
#define TIFR	(*((volatile u8 *)0x58))




#define NORMAL  0
#define	PHASE_CORRECT 1
#define	CTC 2
#define	PWM 3
	


#endif /* TIMERS_PRIVATE_H_ */