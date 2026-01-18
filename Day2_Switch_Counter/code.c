#include <LPC21xx.H>
#include "header.h"

int main() {
    int c = 0;
    IODIR0 = 1;

    while(1) {
        if(((IOPIN0 >> 5) & 1) == 0) {
            IOCLR0 = 1;
            while(((IOPIN0 >> 5) & 1) == 0);
            c++;
        }
        else {
            IOSET0 = 1;
            if(c == 10)
                c = 0;
        }
    }
}

