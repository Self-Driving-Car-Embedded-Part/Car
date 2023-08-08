/*
 * TIMERS_Interface.h
 *
 * Created: 5/1/2023 12:59:45 PM
 *  Author: Dell
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void MTIMER0_voidinit(void);
void MTIMER0_voidStopTimer(void);
void MTIMER0_voidSetPreloadvalue(u8 A_u8PreloadValue);
void MTIMER0_voidSetOvfCallback(void (*ptrToFunction)(void));
void MTIMER0_voidSetOcr0Value(const u8 A_u8Ocr0Value);
void MTIMER0_voidSetCtcCallback(void (*ptrToFunction)(void));


void MTIMER1_voidinit(void);
void MTIMER1_voidSetOcr1aValue(const u16 A_u8Ocr1aValue);
void MTIMER1_voidSetOcr1bValue(const u16 A_u8Ocr1bValue);
void MTIMER1_voidSetIcuCallback(void (*ptrToFunction)(void));
void MTIMER1_voidSetIcuEdgeSelect(const u8 A_u8IcuEdge);

#endif /* TIMERS_INTERFACE_H_ */