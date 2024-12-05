#include <Arduino.h>
#ifndef SDL_H
#define SDL_H
int gb_sdl_update(void);
void gb_sdl_init(void);
void gb_sdl_frame(void);
void gb_sdl_quit(void);
byte* gb_sdl_get_framebuffer(void);
unsigned int gb_sdl_get_buttons(void);
unsigned int gb_sdl_get_directions(void);
#endif
