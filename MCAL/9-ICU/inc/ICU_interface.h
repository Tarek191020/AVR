/*
 * ICU_interface.h
 *
 * Created: 3/23/2024 11:43:47 PM
 *  Author: Tarek Alaa
 */ 


#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

typedef enum
{
	ICU_FALLING_EDGE,
	ICU_RISEING_EDGE
}ICU_EDGE_t;


/* Function to initialize ICU */
void ICU_voidInit(void);

void ICU_voidStartCapture(void);

/*Select the required edge to be detected*/
void ICU_voidEdgeSel(ICU_EDGE_t copy_u8EdgeSEL);

/* Function to get the captured time */
void ICU_voidGetCapturedTime(u32* copy_u32CapturedValue);

/*Clear the timer register value*/
void ICU_voidClearTimerValue(void);

/* Stop capturing input signals */
void ICU_voidStopCapture(void);

/*save the address of the Call back function in a global variable*/
void ICU_voidSetCallBack(void (*copy_pFunActionICU)(void));

/*Disable the Timer1 to stop the ICU Driver*/
void ICU_voidDeInit(void);

#endif /* ICU_INTERFACE_H_ */