#ifndef LCD_H
#define LCD_H
int gb_lcd_cycle(void);
int gb_lcd_get_line(void);
unsigned char gb_lcd_get_stat();
void gb_lcd_write_control(unsigned char);
void gb_lcd_write_stat(unsigned char);
void gb_lcd_write_scroll_x(unsigned char);
void gb_lcd_write_scroll_y(unsigned char);
void gb_lcd_write_bg_palette(unsigned char);
void gb_lcd_write_spr_palette1(unsigned char);
void gb_lcd_write_spr_palette2(unsigned char);
void gb_lcd_set_window_y(unsigned char);
void gb_lcd_set_window_x(unsigned char);
void gb_lcd_set_ly_compare(unsigned char);
#endif
