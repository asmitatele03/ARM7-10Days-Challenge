#include <lpc21xx.h>
#include "header.h"

main()
{
    lcd_init();
    lcd_cmd(0x80);
    lcd_data('a');
    lcd_cmd(0xC0);
    lcd_data('b');
}
