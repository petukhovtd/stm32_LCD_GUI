#ifndef __PARAMETER_H
#define __PARAMETER_H

typedef struct
{
	enum
	{
		TYPE_INTEGER,
		TYPE_FLOAT,
		TYPE_STRING
	} ptype;
	uint8_t type_value;
	uint32_t ivalue;
	float fvalue;
	uint8_t svalue[SVALUE_MAX_NUM][SVALUE_MAX_LEN];
	uint32_t min;
	uint32_t max;
	float step;
	uint32_t mul1;
	uint32_t mul1_level;
	uint32_t mul2;
	uint32_t mul2_level;
	void (*action)(void);
} Parameter;


#endif
