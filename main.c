/**
	***********************************************************
	*	@file					: main.c
	*	@brief				: main body of the project
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




/* Include Starts------------------------------------------*/

#include "SysClock_Init.h"

/* Include Ends--------------------------------------------*/

int main(void){
	System_Init();
	while(1){
		Delay(2000);
	}
}

/* Code End -----------------------------------------------*/