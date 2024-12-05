// #include <stdio.h>
// #include "timer.h"
// #include "rom.h"
// #include "mem.h"
// #include "cpu.h"
// #include "lcd.h"
// #include "sdl.h"

// int main(int argc, char *argv[])
// {
// 	int r;
// 	const char usage[] = "Usage: %s <rom>\n";

// 	if(argc != 2) {
// 		fprintf(stderr, usage, argv[0]);
// 		return 0;
// 	}

// 	r = gb_rom_load(argv[1]);
// 	if(!r)
// 		return 0;

// 	gb_sdl_init();

// 	printf("ROM OK!\n");

// 	gb_mem_init();
// 	printf("Mem OK!\n");

// 	gb_cpu_init();
// 	printf("CPU OK!\n");

// 	while(1)
// 	{
// 		if(!gb_cpu_cycle())
// 			break;

// 		if(!gb_lcd_cycle())
// 			break;

// 		gb_timer_cycle();
// 	}

// 	gb_sdl_quit();

// 	return 0;
// }
