#ifndef __PAGE_H
#define __PAGE_H

#include "parameter.h"
#include "define_config.h"

typedef enum
{
	MOVE_ERROR,
	MOVE_VALUE_OK,
	MOVE_NEXT_PAGE,
	MOVE_PREVIOS_PAGE
} LCD_MOVE_ANS;

typedef enum
{
	MOVE_ACTION_SHOW,
	MOVE_ACTION_NEXT,
	MOVE_ACTION_PREVIOS,
	MOVE_ACTION_ACTION_1
} LCD_MOVE_ACTION;

typedef struct
{
	uint8_t current_parameter;
	uint8_t page_parameter_max;
	Parameter *mass_parameter[LCD_PAGE_PARAMETER_MAX];
	uint8_t cusorYX[2][LCD_PAGE_PARAMETER_MAX];
} LCD_Page_Parameters;

typedef struct
{
	LCD_MOVE_ANS (*move)(LCD_Page_Parameters *p, LCD_MOVE_ACTION n);
	void (*show)(void);
} LCD_Page_Action;

typedef struct
{
	LCD_Page_Parameters PageParameters;
	LCD_Page_Action PageAction;
} LCD_Page;

void LCD_Page_InitStuct(LCD_Page *p);
LCD_MOVE_ANS LCD_Page_Move(LCD_Page_Parameters *p, LCD_MOVE_ACTION n);

#endif
