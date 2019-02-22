#ifndef __LINKPAGE_H
#define __LINKPAGE_H

#include "page.h"
#include "define_config.h"

typedef struct
{
	uint8_t current_page;
	uint8_t link_page_max;
	LCD_Page *mass_page[LCD_PAGE_MAX];
}LCD_link_Page;

typedef struct
{
	void (*move)(LCD_link_Page *lp, LCD_MOVE_ACTION n);
	void (*change_current_value)(LCD_link_Page *lp, signed char n);
} LCD_link_Action;

typedef struct
{
	LCD_link_Page LinkPage;
	LCD_link_Action LinkAction;
} LCD_link;

void LCD_link_InitStruct(LCD_link *l);
void LCD_Move(LCD_link_Page *lp, LCD_MOVE_ACTION n);
void LCD_ChageCurrentParameter(LCD_link_Page *lp, signed char n);

#endif
