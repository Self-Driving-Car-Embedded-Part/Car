/*
 * QUAD_ENCODER_Interface.h
 *
 * Created: 5/13/2023 5:01:00 PM
 *  Author: Dell
 */ 


#ifndef QUAD_ENCODER_INTERFACE_H_
#define QUAD_ENCODER_INTERFACE_H_

#define VELOCITY_PPR 385 // 35 * 11 * 2
#define POSITION_PPR 385
#define INTERVAl 0.01
#define pi 3.14
#define WHEEL_DIAMETER 0.85




//s32 velocityCount  = 0;
//s32 positionCount  = 0;
void HQUADEN_voidinitVelocityEncoder();
void HQUADEN_voidinitPositionEncoder();

s32 HQUADEn_s32getVelocityCount();
s32 HQUADEn_s32getPositionCount();
u8 HQUADEN_u8getCarDirection();
void HQUADEn_voidResetVelocityCount() ;
void HQUADEn_voidResetPositionCount() ;
u8 getCarDirection();
#endif /* QUAD_ENCODER_INTERFACE_H_ */