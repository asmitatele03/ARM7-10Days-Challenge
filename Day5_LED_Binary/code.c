// RHYDOLAS BOARD SWITCH NO

#include <LPC21xx.H>

#define LED  (7<<0)
#define SW   (1<<PIN0)

int main() {
    int c = 1;

    IODIR0 = LED;      // Set LED pin as output
    IOSET0 = LED;      // Initially turn LED ON

    while(1) {

        if((SW) == 0) {
            while(SW == 0);  // Wait for switch release
            IOCLR0 = c;      // Clear LED based on counter
            delay_ms(1000);
            IOSET0 = LED;    // Turn LED ON again
            c++;

            if(c == 8)       // Reset counter after 8 cycles
                c = 0;
        }
    }
}

