🔧 ARM7 LPC2129 – GPIO Input/Output Program

Program demonstrates GPIO input and output on LPC2129 (ARM7).

Button is connected to P0.5 (Input) and LED to P0.0 (Output).

Includes essential header files:

LPC21xx.H → register definitions

header.h → user-defined utilities

Variable c used as a counter for button presses.

GPIO direction set using:

IODIR0 = 1; → makes P0.0 an OUTPUT.

Infinite loop (while(1)) keeps program running continuously.

Button press detection done using:

((IOPIN0 >> 5) & 1) == 0 → checks active LOW button on P0.5.

On button press:

IOCLR0 = 1; → LED turns ON (clearing P0.0).

Program waits for button release to avoid bounce:

while(((IOPIN0 >> 5) & 1) == 0);

Counter increments each time the button is pressed:

c++;

After button release:

IOSET0 = 1; → LED turns OFF.

When counter reaches 10 presses, it resets:

if(c == 10) c = 0;

Useful for learning:

Basic GPIO control

Bitwise operations

Polling method for input

LED/button interfacing

Ideal for beginner ARM7 embedded systems, lab experiments, and student projects.

Code is compatible with Keil µVision and LPC2129 development boards.
