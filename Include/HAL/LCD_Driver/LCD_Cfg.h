/*
 * LCD_Cfg.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_HAL_LCD_CFG_H_
#define INCLUDE_HAL_LCD_CFG_H_


#define LCD_DATA_PORT	DIO_PORTC
#define LCD_CONTROL_PORT DIO_PORTB

#define LCD_RS_PIN	PIN5
#define LCD_RW_PIN  PIN6
#define LCD_E_PIN	PIN7
#define E_DELAY 1
// 0 --> 1 Line
// 1 --> 2 Lines
#define NO_OF_LINES	1

// 0 --> 5*7
// 1 --> 5*10
#define CHARACTER_FONT 0
// 0 --> OFF
// 1 --> ON
#define DISPLAY_STATUS 1


#define CURSER_DISPLAY 1

#define CURSER_BLINK 1

#define I_D 1

#define SHIFT 0

#endif /* INCLUDE_HAL_LCD_CFG_H_ */
