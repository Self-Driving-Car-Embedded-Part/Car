/*
 * CAR.h
 *
 * Created: 5/19/2023 6:51:20 AM
 *  Author: Munsour
 */ 

//#include "../LIB/STD_TYPES.h"
#ifndef CAR_H_
#define CAR_H_






//Low Pass Filter Parameters
#define ALPHA 0.0

f32 lowPassFilter(f32 value);


/************************************************************************/
                                                                    
/************************************************************************/


//void setPosition(u8 position,u8 dir);
//void setCar();

void readACommandFromRasbperry(char* command);
void setBackMotor(u16 duty,u8 direction);
void setSteeringMotor(f32 v,f32 Vmax);
#endif /* CAR_H_ */