#ifndef __DELAY_H
#define __DELAY_H

uint32_t delay;

void Delay_ms(uint16_t ms)
{
	delay = ms*1000;
	while(delay);
}

void Delay_us(uint32_t us)
{
	delay = us;
	while(delay);
}

void Delay_tic(void)
{
	if(delay > 0){
		delay --;
	}
}

#endif
