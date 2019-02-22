# stm32_LCD_GUI
Библиотека содержит набор обьектов(структур) и функций для управления отображением и изменением парамеров и представлений их на LCD экране
Определены следующие объекты:
Parameter - некий параметр который выводится на экран
LCD_Page - страница из строк, отображаемая на экране
LCD_link - страницы обьединенные в массив

1. Если вы хотите использовать имеющийся файл для управления LCD1602
1.1 В файле stm32_lcd_wh1602b.h изменть только номера пинов и буквы портов
1.2 Настроить прерывание таймера (общего или системного) на частоту 1МГц, поместить в прерывание вызов void Delay_tic()
  Далее можете использовать функции Delay_ms(uint16_t ms) и Delay_us(uint32_t us). Эти функции используются так же при управлении экраном
  в фаайле stm32_lcd_wh1602b.c
2. Использование LCD_GUI
2.1. Файл define_config.h содержит дефайны для ограничения размера массивов
2.2. Пример
  #include "LCD_GUI.h"
  
  //Параметры
  Parameter p1, p2, p3, p4
  //Экран
  LCD_link LCD;
  //Страницы
  LCD_Page Page1, Page2, Page3;
  
  //Инициализация начальных значений структур
  Parameter_InitStruct(&p1);
  Parameter_InitStruct(&p2);
  Parameter_InitStruct(&p3);
  Parameter_InitStruct(&p4);
  LCD_link_InitStruct(&LCD);
  LCD_Page_InitStuct(&Page1);
  LCD_Page_InitStuct(&Page2);
  LCD_Page_InitStuct(&Page3);

  //Описание параметров
  p1.ptype = TYPE_STRING;
  p1.max = 2;
  strcpy(p1.svalue[0], "str1");
  strcpy(p1.svalue[1], "str2");
  strcpy(p1.svalue[2], "str3");
  p1.action = &action; //Подключаемая функция void action(void) которую можно вызвать для текущего параметра
  
  p2.max = 1000000;
  p2.min = 100;
  p2.ivalue = 1000;
  p2.mul1 = 10; //Умножители и уровни умножения для изменения параметров энкодером
  p2.mul1_level = 5;
  p2.mul2 = 100;
  p2.mul2_level = 10;
  
  //Описание соединения страниц
  //Общее количество
  LCD.LinkPage.link_page_max = 3;
  //Порядок страниц
  LCD.LinkPage.mass_page[0] = &Page1;
  LCD.LinkPage.mass_page[1] = &Page2;
  LCD.LinkPage.mass_page[2] = &Page3;
  //
  
