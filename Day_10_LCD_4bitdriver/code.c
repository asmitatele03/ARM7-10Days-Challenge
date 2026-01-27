#include <lpc21xx.h>
#include "header.h"

main()
{
    lcd_init();
    lcd_cmd(0x80); //first row
    lcd_data('a');
    lcd_cmd(0xC0); //second row    
    lcd_data('b');
}
