#include <lpc21xx.h>
#include "lcd.h"

void delay_ms(unsigned int ms);

int main(void)
{
    lcd_init();              // Initialize LCD

    int i;
    while(1)
    {
        for(i = 0; i < 16; i++)
        {
            lcd_cmd(0x80 + i);   // Move cursor to position i
            lcd_data('A');       // Display character 'A'
            delay_ms(500);       // Delay to show movement
            lcd_cmd(0x01);       // Clear display
        }
    }
    return 0;
}

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 6000; j++);    // Approx 1ms delay for 60MHz CCLK
}

