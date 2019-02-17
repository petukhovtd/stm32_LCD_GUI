#ifndef __LCD_WH1602B_H
#define __LCD_WH1602B_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

#define     RS_H		GPIOB->BSRRL |= GPIO_BSRR_BS_4	//PB4
#define     RS_L		GPIOB->BSRRH |= GPIO_BSRR_BS_4

#define     EN_H		GPIOB->BSRRL |= GPIO_BSRR_BS_5	//PB5
#define     EN_L		GPIOB->BSRRH |= GPIO_BSRR_BS_5

#define     D0_H		GPIOB->BSRRL |= GPIO_BSRR_BS_7	//PB7
#define     D0_L		GPIOB->BSRRH |= GPIO_BSRR_BS_7

#define     D1_H		GPIOB->BSRRL |= GPIO_BSRR_BS_8	//PB8
#define     D1_L		GPIOB->BSRRH |= GPIO_BSRR_BS_8

#define     D2_H		GPIOE->BSRRL |= GPIO_BSRR_BS_2	//PE2
#define     D2_L		GPIOE->BSRRH |= GPIO_BSRR_BS_2

#define     D3_H		GPIOE->BSRRL |= GPIO_BSRR_BS_4	//PE4
#define     D3_L		GPIOE->BSRRH |= GPIO_BSRR_BS_4

#define     D4_H		GPIOE->BSRRL |= GPIO_BSRR_BS_5	//PE5
#define     D4_L		GPIOE->BSRRH |= GPIO_BSRR_BS_5

#define     D5_H		GPIOE->BSRRL |= GPIO_BSRR_BS_6	//PE6
#define     D5_L		GPIOE->BSRRH |= GPIO_BSRR_BS_6

#define     D6_H		GPIOC->BSRRL |= GPIO_BSRR_BS_13	//PC13
#define     D6_L		GPIOC->BSRRH |= GPIO_BSRR_BS_13

#define     D7_H		GPIOC->BSRRL |= GPIO_BSRR_BS_15	//PC15
#define     D7_L		GPIOC->BSRRH |= GPIO_BSRR_BS_15

void LCD_Init (void);
void LCD_Init_8bit (void);
void LCD_SendBite (uint8_t Out);
void LCD_SendBite8 (uint8_t Out);
void LCD_SendDate (uint8_t Date);
void LCD_SendInstr (uint8_t Instr);
void LCD_SendInstrShort (uint8_t Instr);

void LCD_Clear (void);
void LCD_CursorBlink (uint8_t State);
void LCD_CursorPositionYX (uint8_t Y, uint8_t X);
void LCD_print (uint8_t *str);

#ifdef __cplusplus
}
#endif

#endif
