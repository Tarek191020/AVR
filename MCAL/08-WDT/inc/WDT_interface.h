/*
 * WDT_interface.h
 *
 * Created: 3/19/2024 10:29:29 AM
 *  Author: Tarek Alaa
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

typedef enum
{
	WDT_TIME_16_3_MS,
	WDT_TIME_32_5_MS,
	WDT_TIME_65_MS,
	WDT_TIME_0_13_S,
	WDT_TIME_0_26_S,
	WDT_TIME_0_52_S,
	WDT_TIME_1_S,
	WDT_TIME_2_1_S
}WDT_Time_t;

void WDT_voidEnable(WDT_Time_t copy_enumTime);
void WDT_voidDisable(void);

#endif /* WDT_INTERFACE_H_ */