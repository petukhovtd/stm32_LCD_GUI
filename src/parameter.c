#include "parameter.h"

void Parameter_InitStruct(Parameter *p)
{
	p->ptype = TYPE_INTEGER;
	p->ivalue = 0;
	for(uint8_t i = 0; i < LCD_SVALUE_NUM_MAX; i++)
	{
		for(uint8_t j = 0; j < LCD_SVALUE_LEN_MAX; j++)
		{
			p->svalue[i][j] = 0;
		}
	}
	p->min = 0;
	p->max = 1;
	p->step = 1;
	p->mul1 = 1;
	p->mul1_level = 1;
	p->mul2 = 1;
	p->mul2_level = 1;
};

void Parameter_change(Parameter *p, signed char n)
{
	signed int in = n;
	if (abs(in)>=p->mul2_level) in *= p->mul2;
		else if (abs(in)>=p->mul1_level) in *= p->mul1;

	if ((in<0)&(p->ivalue<abs(in))) p->ivalue = 0;
	else if ((p->ivalue+in)>p->max) p->ivalue = p->max;
		else p->ivalue += in;

	if(p->ivalue < p->min) p->ivalue = p->min;
}
