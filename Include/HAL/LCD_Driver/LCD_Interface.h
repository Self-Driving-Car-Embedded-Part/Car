/*
 * LCD_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Dell
 */


#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_
#define ROW_ONE 1
#define ROW_TWO 2
void HLCD_voidSendCommand(const u8 A_u8Command);
void HLCD_voidSendData(const u8 A_u8Data);
void HLCD_voidInit (void);

void HLCD_voidClearDisplay();
void HLCD_voidSendString(const u8 *A_pu8String);
void HLCD_voidDisplayNumber (u32 A_u32Number);
#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
