// two way switch
#include <LPC21xx.H>

int main() {
    IODIR0 = 1 << 17;       // Configure P0.17 as output (LED)
    IODIR1 = 0x00;          // Configure Port1 pins as input (Switches)

    while(1) {
        // Check if P1.14 or P1.15 is HIGH (switch pressed)
        if (((IOPIN1 >> 14) & 1) || ((IOPIN1 >> 15) & 1)) {
            IOCLR0 = 1 << 17;   // Turn LED ON
        }
        else {
            IOSET0 = 1 << 17;   // Turn LED OFF
        }
    }
}

