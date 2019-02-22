#include "linkpage.h"

void LCD_link_InitStruct(LCD_link *l)
{
	l->LinkPage.current_page = 0;
	l->LinkPage.link_page_max = 0;
	l->LinkAction.move = &LCD_Move;
	l->LinkAction.change_current_value = &LCD_ChageCurrentParameter;
}

void LCD_Move(LCD_link_Page *lp, LCD_MOVE_ACTION n)
{
	LCD_MOVE_ANS ans = lp->mass_page[lp->current_page]->PageAction.move(&lp->mass_page[lp->current_page]->PageParameters, n);
	switch (ans)
	{
		case MOVE_VALUE_OK:
			break;
		case MOVE_NEXT_PAGE:
			lp->current_page++;
			if (lp->current_page == lp->link_page_max) lp->current_page = 0;
			lp->mass_page[lp->current_page]->PageParameters.current_parameter = 0;
			break;
		case MOVE_PREVIOS_PAGE:
			if(lp->current_page == 0) lp->current_page = lp->link_page_max - 1;
			else lp->current_page--;
			lp->mass_page[lp->current_page]->PageParameters.current_parameter = lp->mass_page[lp->current_page]->PageParameters.page_parameter_max - 1;
			break;
		default:
			lp->current_page = 0;
			break;
	}
	lp->mass_page[lp->current_page]->PageAction.show();
}

void LCD_ChageCurrentParameter(LCD_link_Page *lp, signed char n)
{
	Parameter_change(lp->mass_page[lp->current_page]->PageParameters.mass_parameter[lp->mass_page[lp->current_page]->PageParameters.current_parameter], n);
	lp->mass_page[lp->current_page]->PageAction.show();
}
