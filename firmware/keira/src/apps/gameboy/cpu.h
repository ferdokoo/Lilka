#ifndef CPU_H
#define CPU_H
#include "rom.h"
void gb_cpu_init(void);
int gb_cpu_cycle(void);
unsigned int gb_cpu_get_cycles(void);
void gb_cpu_interrupt(unsigned short);
#endif
