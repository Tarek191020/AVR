/*
 * BUTTON_interface.h
 *
 * Created: 3/7/2024 4:30:25 AM
 *  Author: Tarek Alaa
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "BUTTON_config.h"

void BUTTON_voidInit();
void BUTTON_voidGetValue(u8 *copy_pu8value);
void BUTTON_voidActivePullUpResistance();


#endif /* BUTTON_INTERFACE_H_ */