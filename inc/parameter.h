#ifndef __PARAMETER_H
#define __PARAMETER_H

#include "stdint.h"
#include "define_config.h"

typedef struct
{
	enum
	{
		TYPE_NULL,
		TYPE_INTEGER,
		TYPE_STRING
	} ptype;
	uint32_t ivalue;
	uint8_t svalue[LCD_SVALUE_NUM_MAX][LCD_SVALUE_LEN_MAX];
	uint32_t min;
	uint32_t max;
	uint8_t step;
	uint8_t mul1;
	uint8_t mul1_level;
	uint8_t mul2;
	uint8_t mul2_level;
	void (*action)(void);
} Parameter;

void Parameter_InitStruct(Parameter *p);

void Parameter_change(Parameter *p, signed char n);

#endif
