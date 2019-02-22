#include "stm32_lcd_wh1602b.h"

void LCD_Init (void)
{
  Delay_ms(20000);
  LCD_SendInstrShort(0x3);
  Delay_us(5000);
  LCD_SendInstrShort(0x3);
  Delay_us(200);
  LCD_SendInstrShort(0x3);
  Delay_us(200);
  LCD_SendInstrShort(0x2);
  Delay_us(200);
  LCD_SendInstr(0x28);          //4-line 2-str, 5*8
  Delay_us(50);
  LCD_SendInstr(0x08);			//Display OFF
  Delay_us(50);
  LCD_Clear();
  Delay_us(50);
  LCD_SendInstr(0x06);
  Delay_us(50);
  LCD_SendInstr(0x0C);			//Disply ON
  Delay_us(50);
}

void LCD_Init_8bit (void)
{
  Delay_us(20000);
  LCD_SendInstr(0x30);
  Delay_us(5000);
  LCD_SendInstr(0x30);
  Delay_us(200);
  LCD_SendInstr(0x30);
  Delay_us(200);
  LCD_SendInstr(0x38); //Confing 8-bit, 2-line, 5*8
  Delay_us(50);
  LCD_SendInstr(0x08);			//Display OFF
  Delay_us(50);
  LCD_Clear();
  Delay_us(50);
  LCD_SendInstr(0x06);
  Delay_us(50);
  LCD_SendInstr(0x0C);			//Disply ON
  Delay_us(50);
}

void LCD_SendBite (uint8_t Out)
{
  EN_H;
  if(Out&0x80)D7_H; else D7_L;
  if(Out&0x40)D6_H; else D6_L;
  if(Out&0x20)D5_H; else D5_L;
  if(Out&0x10)D4_H; else D4_L;
  Delay_us(10);
  EN_L;
  Delay_us(10);
  EN_H;
  if(Out&0x08)D7_H; else D7_L;
  if(Out&0x04)D6_H; else D6_L;
  if(Out&0x02)D5_H; else D5_L;
  if(Out&0x01)D4_H; else D4_L;
  Delay_us(10);
  EN_L;
  Delay_us(10);
}

void LCD_SendBite8 (uint8_t Out)
{
  EN_H;
  if(Out&0x80)D7_H; else D7_L;
  if(Out&0x40)D6_H; else D6_L;
  if(Out&0x20)D5_H; else D5_L;
  if(Out&0x10)D4_H; else D4_L;
  if(Out&0x08)D3_H; else D3_L;
  if(Out&0x04)D2_H; else D2_L;
  if(Out&0x02)D1_H; else D1_L;
  if(Out&0x01)D0_H; else D0_L;
  Delay_us(1);
  EN_L;
  Delay_us(40);
}

void LCD_SendDate (uint8_t Date)
{
  RS_H;
//  LCD_SendBite(Date);
  LCD_SendBite8(Date);
}

void LCD_SendInstr (uint8_t Instr)
{
  RS_L;
//  LCD_SendBite(Instr);
  LCD_SendBite8(Instr);
}

void LCD_SendInstrShort (uint8_t Instr)
{
  RS_L;
  EN_H;
  if(Instr&0x08)D7_H; else D7_L;
  if(Instr&0x04)D6_H; else D6_L;
  if(Instr&0x02)D5_H; else D5_L;
  if(Instr&0x01)D4_H; else D4_L;
  Delay_us(1);
  EN_L;
  Delay_us(30);
}

void LCD_Clear (void)
{
  LCD_SendInstr(0x01);
  Delay_us(1600);
}

void LCD_CursorBlink (uint8_t State)
{
  if (State=='E')      LCD_SendInstr(0x0D);
      else LCD_SendInstr(0x0C);

  Delay_us(50);
}

void LCD_CursorPositionYX (uint8_t Y, uint8_t X)
{
  LCD_SendInstr(0x80+Y*0x40+X);
  Delay_us(50);
}

void LCD_print (uint8_t *str)
{
  char data;
  while (*str)
  {
    data=*str++;
    LCD_SendDate(data);
  }
}
