//========================================
//程序说明:       STM32F107VC中断等级配置
//端口使用: 
//创建者:          FangYikaii   
//创建时间:       2017-01-17 
//修改时间:       2013-01-17 
//========================================
//========================================
//优先程度：先抢断NVIC_IRQChannelPreemptionPriority--再响应NVIC_IRQChannelSubPriority
//中断向量  抢占优先级  响应优先级
//A          0          0
//B          1          0
//C          1          1
//正在执行C,C可被抢占优先级更高的A打断，B和C的抢占优先级一样，C不能被B打断�
//若B、C同时到达，B先响应

//头文件
#include "main.h"

//========================================
//变量定义



//========================================
//函数声明

void NVIC_Configuration(void);      //中断等级配置  


//========================================
//子模块函数

/*******************************************************************************
* Function Name    : void NVIC_Configuration(void)
* Description          : Configures the used IRQ Channels and sets their priority.
* Input                   : None
* Output                : None
* Return                : None
*******************************************************************************/
/***********************************************************************
函数名称： void NVIC_Configuration(void)
功    能：中断等级配置
输入参数：
输出参数：
编写时间：2017.01.16
编 写 人：
注    意：
IO中断对应的中断句柄关系为：	GPIOX0 -- EXTI0_IRQHandler
															GPIOX1 -- EXTI1_IRQHandler					
															GPIOX2 -- EXTI1_IRQHandler	
															GPIOX3 -- EXTI1_IRQHandler					
															GPIOX4 -- EXTI1_IRQHandler	

															GPIOX5~GPIOX9 -- EXTI9_5_IRQHandler						
															GPIOX10~GPIOX15 -- EXTI15_10_IRQHandler	
***********************************************************************/
void NVIC_Configuration(void)
{ 
  NVIC_InitTypeDef NVIC_InitStructure;
	
  /* Set the Vector Table base address at 0x08000000 */
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0000);
// 			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);			//抢断优先级 0   		响应优先级 0-15	
// 			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//抢断优先级 0-1    响应优先级 0-7	
// 			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			//抢断优先级 0-3    响应优先级 0-3	
// 			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);			//抢断优先级 0-7    响应优先级 0-1	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);			//抢断优先级 0-15   响应优先级 0
  
	//USART1_IRQn
	/* Enable the USART1_IRQn gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	              //设定通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;       //抢断优先级设置 0 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	            //响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
	
	//USART2_IRQn
	/* Enable the USART2_IRQn gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	              //设定通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;       //抢断优先级设置 0 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	            //抢断优先级设置 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//TIM5-普通计时
	//优先程度低【抢断=15】
	/* Enable the TIM5 gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;							//设定通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;	//抢断优先级设置  0或1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;					//响应优先级设置
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure); 
	
	//TIM4-频率测量
	/* Enable the TIM5 gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =5;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);


// 	NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =6;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);   
}
