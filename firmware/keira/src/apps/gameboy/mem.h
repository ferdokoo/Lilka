#ifndef MEM_H
#define MEM_H
#ifdef __cplusplus

extern "C" {

#endif

#include "rom.h"
void gb_mem_init(void);
unsigned char gb_mem_get_byte(unsigned short);
unsigned short gb_mem_get_word(unsigned short);
void gb_mem_write_byte(unsigned short, unsigned char);
void gb_mem_write_word(unsigned short, unsigned short);
void gb_mem_bank_switch(unsigned int);
unsigned char gb_mem_get_raw(unsigned short);
#ifdef __cplusplus

  }

#endif /* end of __cplusplus */
#endif
