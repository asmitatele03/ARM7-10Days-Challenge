Delay functions

#include <LPC21xx.h>
#include "header.h"

void delay_sec(unsigned int sec)
{
    T0PR = 15000000 - 1;
    T0PC = 0;
    T0TC = 0;
    T0TCR = 1;

    while(T0TC < sec);

    T0TCR = 0;
}

void delay_ms(unsigned int ms)
{
    T0PR = 15000 - 1;
    T0PC = 0;
    T0TC = 0;
    T0TCR = 1;

    while(T0TC <= ms);

    T0TCR = 0;
}

header.h
extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);

lcd_8bit_driver.c
#include <LPC21xx.h>
#include "header.h"

void lcd_data(unsigned char data)
{
    IOCLR0 = 0x7F;         // Clear data pins
    IOSET0 = data;         // Put data on port
    IOSET0 = 1<<8;         // RS = 1 (data)
    IOCLR0 = 1<<9;         // RW = 0 (write)
    IOSET0 = 1<<10;        // EN = 1
    delay_ms(2);
    IOCLR0 = 1<<10;        // EN = 0
}

void lcd_cmd(unsigned char cmd)
{
    IOCLR0 = 0x7F;         // Clear data pins
    IOSET0 = cmd;          // Command output
    IOCLR0 = 1<<8;         // RS = 0 (command)
    IOCLR0 = 1<<9;         // RW = 0
    IOSET0 = 1<<10;        // EN = 1
    delay_ms(2);
    IOCLR0 = 1<<10;        // EN = 0
}

void lcd_init()
{
    IODIR0 = 0x7FF;        // Set P0.0–P0.10 as output
    IOCLR0 = 0x7FF;

    lcd_cmd(0x38);         // 8-bit, 2 line
    lcd_cmd(0x0E);         // Display ON, cursor ON
    lcd_cmd(0x01);         // Clear display
}







