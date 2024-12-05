#include <stdio.h>
#include "timer.h"
#include "rom.h"
#include "mem.h"
#include "cpu.h"
#include "lcd.h"
#include "sdl.h"
#include "gbrom.h"
#include "gameboy.h"

GameBoyApp::GameBoyApp(String path) : App("GameBoy", 0, 0, lilka::display.width(), lilka::display.height()) {
    argv[0] = new char[path.length() + 1];
    strcpy(argv[0], path.c_str());
}

GameBoyApp::~GameBoyApp() {
    int r = gb_rom_init(gb_rom);

    gb_sdl_init();

    printf("ROM OK!\n");

    gb_mem_init();
    printf("Mem OK!\n");

    gb_cpu_init();
    printf("CPU OK!\n");  
    delete[] argv[0];
}

void GameBoyApp::run() {
    while(1){
      gb_cpu_cycle();

      gb_lcd_cycle();

      gb_timer_cycle();
    }
}