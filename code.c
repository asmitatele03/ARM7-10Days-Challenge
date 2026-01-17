#include <lpc21xx.h>
#define LED 0xFF
#include "header.h"

int main()
{
    int i;
    IODIR0 |= LED;       // Configure P0.0–P0.7 as output

    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            IOCLR0 = (1 << i);   // Turn ON LED at position i
            delay_ms(200);

            IOSET0 = (1 << i);   // Turn OFF LED
            delay_ms(200);
        }
    }
}
