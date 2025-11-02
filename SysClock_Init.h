/**
	***********************************************************
	*	@file					: SysClock.h
	*	@brief				: System Clock Initializing Header File
	***********************************************************
	*	@info
	*	The project EmbeddedProject_F746_V1 is created for EE304 
	*	course by the group members:
	*	1. Metehan Saman
	*	2. Emirhan Sonmez
	*	3. Yusuf Herdem
	*
	***********************************************************
	*	@info
	*	GitHub Page Link:
	*	https://github.com/MetehanSaman/Smart-Comfort-Monitoring-System
	*
	***********************************************************
*/
/* Code Start ---------------------------------------------*/

#ifndef SYSCLOCK_INIT_H
#define SYSCLOCK_INIT_H


/* Include Starts------------------------------------------*/
#include "stm32f746xx.h"
#include <stdint.h>
/* Include Ends--------------------------------------------*/


/* Variable Definations Starts-----------------------------*/
void System_Init(void);
void Delay(uint16_t ms);
/* Variable Definations Ends-------------------------------*/


/* Functions Starts----------------------------------------*/
/* Functions Ends------------------------------------------*/


#endif

/* Code End -----------------------------------------------*/
