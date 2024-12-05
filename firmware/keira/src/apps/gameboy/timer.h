#ifndef TIMER_H
#define TIMER_H
void gb_timer_set_tac(unsigned char);
void gb_timer_cycle(void);
unsigned char gb_timer_get_div(void);
unsigned char gb_timer_get_counter(void);
unsigned char gb_timer_get_modulo(void);
unsigned char gb_timer_get_tac(void);
void gb_timer_set_div(unsigned char);
void gb_timer_set_counter(unsigned char);
void gb_timer_set_modulo(unsigned char);
#endif