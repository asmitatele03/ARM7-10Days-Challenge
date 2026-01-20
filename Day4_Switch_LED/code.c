#include <LPC212x.h>

int main()
{
    IODIR0 = 1;     // Configure P0.1 as output

    while (1)
    {
        if (((IOPIN0 >> 5) & 1) == 0)   // Read input at P0.5 (active low)
        {
            IOCLR0 = 1;           // Clear P0.1 → LED ON
        }
        else
        {
            IOSET0 = 1;           // Set P0.1 → LED OFF
        }
    }
}

