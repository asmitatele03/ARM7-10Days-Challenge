#include <LPC212x.h>

int main()
{
    IODIR0 = 1 << 1;     // Configure P0.1 as output

    while (1)
    {
        if (((IOPIN0 >> 5) & 1) == 0)   // Check input at P0.5
        {
            IOCLR0 = 1 << 1;           // Clear P0.1 (LED ON – active low)
        }
        else
        {
            IOSET0 = 1 << 1;           // Set P0.1 (LED OFF)
        }
    }
}

