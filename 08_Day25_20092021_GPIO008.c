/*
===============================================================================
 Name        : 08_Day25_20092021_GPIO008.c

 Description : GPIO Input using a push button as a switch



 Layered Architecture used for this project
 ************************************
 Application layer-08_Day25_20092021_GPIO008.c
 ************************************
 Board layer - led.c/.h, button.c/.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "led.h"
#include "button.h"
/* Private typedef -----------------------------------------------------------*/

/* States of the system */
typedef enum {LEDOFF=0,LEDON=1}States_t;
/* Inputs to the system */
typedef enum {NONE=0,BUTTONPRESS=1} Inputs_t;

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vLedInitialize();
	vButtonInitialize();
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	uint8_t buttonstatus=0,ledstatus=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
	  if(ucButtonState(BUTTON_0)==BUTTON_PRESSED)
	  {
		  buttonstatus =1;

	  }

	  if (ucButtonState(BUTTON_0)==BUTTON_NOTPRESSED)
	  {
		  if(buttonstatus)
		  {
			  ledstatus^=1;
			  buttonstatus=0;

			  /* You can write the increment of num for displaying */

		  }
	  }

	  if(ledstatus)
		  vLedOn(LED_0);
	  else
		  vLedOff(LED_0);


  }
  /* End of Application entry point */
}




