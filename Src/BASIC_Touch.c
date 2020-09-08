/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2004  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "main.h"
#include  <stm32f7xx_hal.h>
#include "stdlib.h"
#include "math.h"
#define INT_MAX 2147483647
#define INT_MIN (-2147483647-1)
/* UART handler declaration */
UART_HandleTypeDef UartHandle;

void UART_Config(void);
 char* int_to_str(int iVal);
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
	char* int_to_str(int iVal)
{
	static char str[12];
	int isNegative = 0;
	int i = 0,j=0;
	if (iVal == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	if (iVal == INT_MIN)
	{
		int_to_str(iVal + 1);
		char *tmp = str;
		while (*tmp != '\0')
			tmp++;
		tmp--;
		*tmp += 1;
		return str;
	}
	if (iVal < 0)
	{
		iVal *= -1;
		isNegative = 1;
		str[i++] = '-';
		j++;
	}
	while (iVal)
	{
		str[i++]=iVal % 10+'0';
		iVal /= 10;
	}
	str[i--] = '\0';
	while (j < i)
	{
		char ch = str[i];
		str[i--] = str[j];
		str[j++] = ch;
	}
	return str;
}
void MainTask(void) {
	GUI_PID_STATE State;	 
	newgame:
	GUI_SetBkColor(GUI_YELLOW);
	GUI_Clear();
	GUI_SetColor(GUI_BROWN);//dong
	GUI_SetTextAlign(50);
	GUI_CURSOR_Show();
	int speed=0;
  GUI_DrawRect(220,50,320,100);
	GUI_DrawRect(220,120,320,170);
	GUI_DrawRect(220,190,320,240);
	GUI_DispStringHCenterAt("primary",270, 65);
	GUI_DispStringHCenterAt("middle",270, 140);
	GUI_DispStringHCenterAt("senior",270, 205);
	while(1){
		GUI_TOUCH_GetState(&State);
				if (State.Pressed == 1) {
							GUI_Exec();//shuaxin shishi anjian
						if(((State.x-270)*(State.x-270))<=2500&&((State.y-65)*(State.y-65))<=600)
					{
							speed=3;
							break;
					}
						if(((State.x-270)*(State.x-270))<=2500&&((State.y-140)*(State.y-140))<=600)
					{
							speed=2;
							break;
					}
						if(((State.x-270)*(State.x-270))<=2500&&((State.y-205)*(State.y-205))<=600)
					{
							speed=1;
							break;
					}
				}
	}
	gamestart:	GUI_Clear();
	int grade=0;
	int num,q,drawrect;
	int k=0;
	int timecount1=30;
	drawrect=0;
	GUI_Delay(500);
	mytimecount=0;
  while(1)
	{		
		timecount1=30-timereturn();
		k=0;
		q = rand();
		srand(q);
		num=rand()%8;
		//
		for(k=0;k<8;k++){
			if(k<4){
				GUI_FillEllipse(100+k*100,120,45,10);
			}
			else{
				GUI_FillEllipse(100+(k-4)*100,220,45,10);
			}
		}
		GUI_DispStringHCenterAt("CORE:",320,25);
		GUI_DispStringHCenterAt(int_to_str(grade),350, 25);
		GUI_DispStringHCenterAt("COUNTDOWN:",150, 25);
		GUI_DispStringHCenterAt(int_to_str(timecount1),200, 25);
		if(num<4){
						GUI_SetColor(0xc6c5c5);//laoshu
						for(drawrect=0;drawrect<50;drawrect++){
								GUI_FillRect(90+num*100,124-drawrect,110+num*100,125-drawrect);
								GUI_Delay(5);
						}
						//GUI_FillRect(100+num*100,125,40,50);
						GUI_FillCircle(100+num*100,100,28);
						GUI_SetColor(GUI_WHITE);//yanjing
						GUI_FillCircle(93+num*100,88,5);
						GUI_FillCircle(107+num*100,88,5);
						GUI_SetColor(GUI_BLACK);//yanzhu
						GUI_FillCircle(93+num*100,86,2);
						GUI_FillCircle(107+num*100,90,2);
						GUI_SetColor(0xffcef1);//zuiba xia						
						GUI_FillCircle(100+num*100,107,10);
						GUI_SetColor(0xc6c5c5);//zuiba shang
						GUI_FillCircle(100+num*100,102,10);
						GUI_SetColor(GUI_BROWN);//hole
			}
			else{
				    GUI_SetColor(0xc6c5c5);//laoshu
						for(drawrect=0;drawrect<50;drawrect++){
								GUI_FillRect(90+(num-4)*100,224-drawrect,110+(num-4)*100,225-drawrect);
								GUI_Delay(5);
						}
						//GUI_FillRect(100+(num-3)*100,225,40,50);
						GUI_FillCircle(100+(num-4)*100,200,28);
						GUI_SetColor(GUI_WHITE);
						GUI_FillCircle(93+(num-4)*100,188,5);
						GUI_FillCircle(107+(num-4)*100,188,5);
						GUI_SetColor(GUI_BLACK);
						GUI_FillCircle(93+(num-4)*100,186,2);
						GUI_FillCircle(107+(num-4)*100,190,2);
						GUI_SetColor(0xffcef1);//zuiba xia						
						GUI_FillCircle(100+(num-4)*100,207,10);
						GUI_SetColor(0xc6c5c5);//zuiba shang
						GUI_FillCircle(100+(num-4)*100,202,10);
						GUI_SetColor(GUI_BROWN);
				}
		printf("%s",int_to_str(grade));
		int u=0;
		int selectp=0;
		for(u=0;u<3000000*speed;u++){
				GUI_TOUCH_GetState(&State);
				if (State.Pressed == 1) {
							GUI_FillCircle(State.x, State.y, 2);
							printf("Location(%d, %d)\r\n", State.x, State.y);
							GUI_Exec();
							for(k=0;k<8;k++){
									if(k<4&&((State.x-100-k*100)*(State.x-100-k*100)+(State.y-100)*(State.y-100))<=2500){									
													selectp=1;
									}
									if(k>3&&((State.x-100-(k-4)*100)*(State.x-100-(k-4)*100)+(State.y-200)*(State.y-200))<=2500){									
													selectp=1;
									}
							}
							if(selectp==1){
								selectp=0;
								break;
							}
				}
		}	
		int mouseX,mouseY;
		int d;
		if(num<4){
			mouseX=100+num*100;
			mouseY=100;
		}else{
			mouseX=100+(num-4)*100;
			mouseY=200;
		}
		d = (int)(((int)State.x-mouseX)*((int)State.x-mouseX) + ((int)State.y-mouseY)*((int)State.y-mouseY));
		if (d > 2500){ 
			    mytimecount++;
					GUI_DispStringHCenterAt("-2",220, 25);
		} else{ 
					grade++;
			 	  GUI_DispStringHCenterAt("+1",370, 25);
		} 
		timecount1--;
		if(timecount1<0)
		{
			GUI_Clear();			
			GUI_DispStringHCenterAt("TIME OVER!!!",200,100);
			GUI_DispStringHCenterAt("final grade:",200,150);
			GUI_DispStringHCenterAt(int_to_str(grade),250, 150);
			
	//exit and return button
		GUI_Delay(3000);
		GUI_Clear();
		GUI_DrawRect(220,50,320,100);
	  GUI_DrawRect(220,120,320,170);
		GUI_DispStringHCenterAt("game again",270, 65);
	  GUI_DispStringHCenterAt("exit",270, 140);
	
			while(1){
		GUI_TOUCH_GetState(&State);
				if (State.Pressed == 1) {
							//GUI_FillCircle(State.x, State.y, 2);
							GUI_Exec();//shuaxin shishi anjian
						if(((State.x-270)*(State.x-270))<=2500&&((State.y-65)*(State.y-65))<=600)
					{
						mytimecount=0;
						goto gamestart;
					}
						if(((State.x-270)*(State.x-270))<=2500&&((State.y-140)*(State.y-140))<=600)
					{
						GUI_Clear();
						GUI_DispStringHCenterAt("game over",200, 100);
						GUI_Delay(500);
						mytimecount=0;
						goto newgame;
					}
				}
	}		
	}		
		GUI_Delay(800);
		GUI_Clear();	
	
}
	}

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO TX/RX clock */
  USARTx_TX_GPIO_CLK_ENABLE();
  USARTx_RX_GPIO_CLK_ENABLE();

  /* Select SysClk as source of USART1 clocks */
  RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  RCC_PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);

  /* Enable USARTx clock */
  USARTx_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = USARTx_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Alternate = USARTx_TX_AF;

  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Alternate = USARTx_RX_AF;

  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  /*##-1- Reset peripherals ##################################################*/
  USARTx_FORCE_RESET();
  USARTx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks #################################*/
  /* Configure UART Tx as alternate function  */
  HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
  /* Configure UART Rx as alternate function  */
  HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);

}

void UART_Config(void)
{
	  /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
  /* UART1 configured as follow:
      - Word Length = 8 Bits
      - Stop Bit = One Stop bit
      - Parity = NONE parity
      - BaudRate = 115200 baud
      - Hardware flow control disabled (RTS and CTS signals) */
  UartHandle.Instance          = USARTx;
  
  UartHandle.Init.BaudRate     = 115200;
  UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits     = UART_STOPBITS_1;
  UartHandle.Init.Parity       = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode         = UART_MODE_TX_RX;
  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
    
  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    /* Initialization Error */
    while(1)
		{
		}
  }
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 0xFFFF); 

  return ch;
}


/*************************** End of file ****************************/
