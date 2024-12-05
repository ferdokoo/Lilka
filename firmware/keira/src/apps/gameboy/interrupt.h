#ifndef INTERRUPT_H
#define INTERRUPT_H

void gb_interrupt(unsigned int);
void gb_interrupt_disable(void);
void gb_interrupt_enable(void);
unsigned char gb_interrupt_get_IF(void);
void gb_interrupt_set_IF(unsigned char);
unsigned char gb_interrupt_get_mask(void);
void gb_interrupt_set_mask(unsigned char);
int gb_interrupt_pending(void);
int gb_interrupt_flush(void);

enum {
	INTR_VBLANK  = 0x01,
	INTR_LCDSTAT = 0x02,
	INTR_TIMER   = 0x04,
	INTR_SERIAL  = 0x08,
	INTR_JOYPAD  = 0x10
};
#endif
