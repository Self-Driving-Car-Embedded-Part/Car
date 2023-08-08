/*
 * DIO_Interface.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_FLOATING 0
#define DIO_PULLUP 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



void MDIO_voidInit(void);
void MDIO_voidSetPinDirection(const u8 A_u8Port,const u8 A_u8Pin,const u8 A_u8Direction);
void MDIO_voidSetPinValue(const u8 A_u8Port,const u8 A_u8Pin,const u8 A_u8Value);
u8 MDIO_u8GetPinValue(const u8 A_u8Port,const u8 A_u8Pin);
void MDIO_voidSetPortDirection(const u8 A_u8Port,const u8 A_u8Direction);
void MDIO_voidSetPortValue(const u8 A_u8Port,const u8 A_u8Value);
void MDIO_voidTogglePin(const u8 A_u8Port,const u8 A_u8Pin);


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
