#include "page.h"

void LCD_Page_InitStuct(LCD_Page *p)
{
	p->PageParameters.current_parameter = 0;
	p->PageParameters.page_parameter_max = 0;
	p->PageAction.move = &LCD_Page_Move;
}

LCD_MOVE_ANS LCD_Page_Move(LCD_Page_Parameters *p, LCD_MOVE_ACTION n)
{
	LCD_MOVE_ANS ans = MOVE_ERROR;

	switch (n)
	{
		case MOVE_ACTION_ACTION_1:
			p->mass_parameter[p->current_parameter]->action();
			ans = MOVE_VALUE_OK;
			break;
		case MOVE_ACTION_NEXT:
			if (p->current_parameter == (p->page_parameter_max - 1)) ans = MOVE_NEXT_PAGE;
			else
			{
				p->current_parameter++;
				ans = MOVE_VALUE_OK;
			}
			break;
		case MOVE_ACTION_PREVIOS:
			if (p->current_parameter == 0) ans = MOVE_PREVIOS_PAGE;
			else
			{
				p->current_parameter--;
				ans = MOVE_VALUE_OK;
			}
			break;
		case MOVE_ACTION_SHOW:
			ans = MOVE_VALUE_OK;
			break;
		default:
			ans = MOVE_VALUE_OK;
			break;
	}
	return ans;
}
