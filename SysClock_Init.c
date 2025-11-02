/**
	***********************************************************
	*	@file					: SysClock.c
	*	@brief				: System Clock Initializing Source File
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


/* Variable Definations Starts-----------------------------*/
/* Variable Definations Ends-------------------------------*/


/* Functions Starts----------------------------------------*/
void System_Init(void){
	
	#define PLL_M  25
	#define PLL_N  432
	#define PLL_P  0
	
	/* First, set the HSE on and wait untill it is ready*/
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	
	/* Power Enable */
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	
	/* Voltage Regulator */
	PWR->CR1 = (PWR->CR1 & ~PWR_CR1_VOS_Msk); // Resetting VOS
	PWR->CR1 |= (PWR_CR1_VOS_0 | PWR_CR1_VOS_1); // Setting VOS bits as 11 which is scale 1 mode
	PWR->CR1 |= PWR_CR1_ODEN;
	PWR->CR1 |= PWR_CR1_ODSWEN;
	
	/* Configure the FLASH */
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	FLASH->ACR |= FLASH_ACR_LATENCY_7WS;
	
	/* AHB, APB1, APB2  Config. */
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2;
	
	/* PLL Config. */
	RCC -> PLLCFGR = (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | RCC_PLLCFGR_PLLSRC_HSE ;
	
	/* Turn on the PLL and wait until it is ready */
	RCC -> CR |= RCC_CR_PLLON;
	while (!(RCC -> CR & RCC_CR_PLLRDY));
	
	while(!(PWR->CSR1 & PWR_CSR1_VOSRDY)); // Wait for VOS to be ready as its working when PLL is on
	while(!(PWR->CSR1 & PWR_CSR1_ODRDY)); // Wait for ODEN to be ready
	while(!(PWR->CSR1 & PWR_CSR1_ODSWRDY)); // Wait for ODSWEN to be ready
	
	/* Switch the CLK to HSE and wait untill it is switched */
	RCC -> CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC -> CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
	
	/*Enable Delay Clokc (TIM2[108MHz]) **************************************/
	RCC -> APB1ENR |= (1 << 0); //Enable TIM2 CLK
	
	TIM2 -> PSC = 108-1;
	TIM2 -> ARR = 0Xffff;
	
	TIM2 -> CR1 |= (1 << 0);
	while(!(TIM2 -> SR & (1 << 0)));
}


/*Delay Functions **********************************************************/
void Delay_us(uint16_t us){
	
	TIM2 -> CNT = 0;
	while (TIM2 ->CNT  < us);
	
}


void Delay(uint16_t ms){
	
	for (uint16_t i = 0; i<ms; i++){
		Delay_us(1000);
	}
}

/* Functions Ends------------------------------------------*/



/* Code End -----------------------------------------------*/
