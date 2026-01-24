#include <lpc21xx.h>
#include "header.h"

int main()
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
}


