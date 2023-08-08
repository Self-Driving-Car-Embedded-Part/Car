/*
 * TIMERS_Cfg.h
 *
 * Created: 5/1/2023 1:00:02 PM
 *  Author: Dell
 */ 


#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_

/**TIMER0**/
#define TIMER0_MODE CTC
#define TIMER0_CLK_CFG 5
#define OCR0_VALUE 177
#define TIMER0_CTC_OUTPUT_MODE 0

//0 normal
//1 reserved
//2 non_inv
//3 inv
#define TIMER0_PWM_MODE 5
//0 normal
//1 reserved
//2 non_inv
//3 inv
#define TIMER0_PHASE_CORRECT_MODE 2
/*********/

/**TIMER1*/
#define TIMER1_CLK_CFG 2
#define TIMER1_ICR1_VALUE 0

#define OCR1A_VALUE 0
#define OCR1B_VALUE 0

#define TIMER1_ICU_ENABLE 0
//0 FALLING
//1 RISING
#define TIMER1_ICU_EDGE_SELECT 1
/********/
#endif /* TIMERS_CFG_H_ */