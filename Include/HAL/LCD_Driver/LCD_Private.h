/*
 * LCD_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_HAL_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_PRIVATE_H_

#define E_DELAY	2
#define INIT_VDD_DELAY 32

#define DONT_CARE_BIT	0

#define FUNCTION_SET CONC_BIT(0,0,1,1,NO_OF_LINES,CHARACTER_FONT,DONT_CARE_BIT,DONT_CARE_BIT)
#define DISPLAY_ON_OFF_CONTROL CONC_BIT(0,0,0,0,1,DISPLAY_STATUS,CURSER_DISPLAY,CURSER_BLINK)
//#define RETURN_HOME
#define DISPALY_CLEAR 0x01
#define ENTRY_MODE_SET CONC_BIT(0,0,0,0,0,1,I_D,SHIFT)
#define LCD_ROW_ONE 127
#define LCD_ROW_TWO 191
#endif /* INCLUDE_HAL_LCD_PRIVATE_H_ */
