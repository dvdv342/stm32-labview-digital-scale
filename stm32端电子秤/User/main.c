#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "hx711.h"
#include "Serial.h"
#include <stdio.h>

// 修改变量类型，防止溢出
int32_t value;
float weight;
int32_t reset;
u8 buff[30];  

// 标定参数
float Weights = 208;
int32_t Weights_100 = 8878600;

int main(void)
{

	/* 模块初始化 */
	OLED_Init();
	HX711_Init();
	Serial_Init();	

	Serial_Printf("System Start!\r\n");

	/* OLED 固定显示 */
	OLED_ShowString(1, 1, "Weight:");
	OLED_ShowString(2, 1, "Value:");
	reset = HX711_GetData();
	
	while (1)
	{
		// 1. 读取HX711
		value = HX711_GetData();
		
		// 2. 计算重量
		weight = (float)(value - reset) * Weights / (float)(Weights_100 - reset);

		// 3. 浮点转字符串
		sprintf((char*)buff, "%.2f", weight);
		
		// 4. OLED显示
		OLED_ShowString(1, 8, (char*)buff);
		OLED_ShowNum(2, 8, value, 8);
		
		// 5. 修正：串口发送真实重量
		Serial_SendString((char*)buff);
		//Serial_SendString("\r\n"); 
		Delay_ms(500);
		//Serial_SendNumber(value, 7);
		//Serial_SendString("\r\n"); 
		//Delay_ms(500);
	}
}
