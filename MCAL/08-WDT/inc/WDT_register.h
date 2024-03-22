/*
 * WDT_register.h
 *
 * Created: 3/19/2024 10:30:56 AM
 *  Author: Tarek Alaa
 */ 


#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

//WatchDogTimeControlReg
#define WDTCR_REG      *((volatile u8*)0x41)

#define WDP0           0
#define WDP1           1
#define WDP2           2
#define WDE            3
#define WDTOE          4

#endif /* WDT_REGISTER_H_ */