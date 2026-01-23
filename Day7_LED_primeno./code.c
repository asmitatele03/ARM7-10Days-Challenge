#include <LPC21xx.H>
#include "header.h"

int main() {
    int i = 1, j, c;
    IODIR0 = 255;
    IOSET0 = 255;

    while(1) {

        for (j = 1, c = 0; j <= i; j++) {
            if (i % j == 0)
                c++;
        }

        if (c == 2) {
            IOCLR0 = 1 << i;
            delay_ms(200);
            IOSET0 = 1 << i;
        }

        i++;
    }
}

