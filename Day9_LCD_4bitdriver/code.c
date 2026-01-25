#include<lpc21xx.h>
#include"header.h"
main()
{
    int i;
    lcd_init();
    while(1)
    {
        for(i = 0; i < 16; i++)
        {
            lcd_cmd(0x80 + i);   // First row, moving forward
            lcd_data('A');

            lcd_cmd(0xC0 + (15 - i)); // Second row, moving backward
            lcd_data('Z');

            delay_ms(500);
            lcd_cmd(0x01);     // Clear display
        }
    }
}

