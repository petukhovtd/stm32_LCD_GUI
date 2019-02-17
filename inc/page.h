#ifndef __PAGE_H
#define __PAGE_H

#include "stdio.h"
#include "stdarg.h"

typedef struct
{
	uint8_t line_format[LCD_LINE][LCD_WIDTH];
	Parameter* line_parameter[LCD_LINE][LCD_MAX_PARAM_LINE];
	uint8_t line[LCD_LINE][LCD_WIDTH];
} LCD_Page;

uint8_t subsprintf(uint8_t *buffer, uint8_t *format, Parameter **mass);

void LCD_Page_SetLine(LCD_Page *page, uint8_t numberline,
					uint8_t *format, uint8_t numarg, ...)
{
	va_list arg;
	uint8_t count = 0;

	while(*format)
	{
		page->line_format[numberline][count] = *format++;
		count++;
	}
	count = 0;
	va_start(arg, numarg);
	while(numarg--)
	{
		page->line_parameter[numberline][count] = va_arg(arg, Parameter *);
		count++;
	}
	va_end(arg);
}

void LCD_Page_GenerateLine(LCD_Page *page)
{
	for(uint8_t i = 0; i < LCD_LINE; i++)
	{
		subsprintf(&page->line[i], &page->line_format[i], &page->line_parameter[i]);
	}
}

uint8_t subsprintf(uint8_t *buffer, uint8_t *format, Parameter **mass)
{
	uint8_t shift_outs = 0;
	uint8_t subs[16] = {0,};
	uint8_t len = 0;
	uint8_t c = 0;
	while (*format)
	{
		c = *format++;
		subs[len] = c;
		len++;
		if (c == '%')
		{
			while ((c != 'd')&(c != 'f')&(c != 's'))
			{
				c = *format++;
				subs[len] = c;
				len++;
			}
			switch (c)
			{
				case 'd':
					shift_outs += sprintf(buffer+shift_outs, subs, (**mass).ivalue);
					break;
				case 'f':
					shift_outs += sprintf(buffer+shift_outs, subs, (**mass).fvalue);
					break;
				case 's':
					shift_outs += sprintf(buffer+shift_outs, subs, (**mass).svalue[(**mass).ivalue]);
					break;
				default:
					break;
			}
			**mass++;
			for (uint8_t i=0; i<len; i++)
			{
				subs[i] = 0;
			}
			len = 0;
		}
	}
	for (uint8_t i = 0; i < len; i++)
	{
		buffer[shift_outs]=subs[i];
		shift_outs++;
	}
	return shift_outs;
}

#endif
