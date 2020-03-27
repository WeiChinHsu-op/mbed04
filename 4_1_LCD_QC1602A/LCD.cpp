#include "LCD.h"

DigitalOut RS(D2);
DigitalOut E(D3);
BusOut data(D4,D5,D6,D7);

void toggle_enable(void)
{
    E = 1;
    wait(0.001);
    E = 0;
    wait(0.001);
}

//initialize LCD function
void LCD_init(void)
{
    wait(0.02);
    RS = 0;
    E = 0;

    data = 0x2;
    toggle_enable();
    data = 0x8;
    toggle_enable();

    data = 0x0;
    toggle_enable();
    data = 0xF;
    toggle_enable();

    data = 0x0;
    toggle_enable();
    data = 0x1;
    toggle_enable();

void display_to_LCD(char value)
{
    RS = 1;
    data = value>>4;
    toggle_enable();
    data = value;
    toggle_enable();
}

void set_location(char location)
{
    RS=0;
    data=(location|0x80)>>4;        // upper nibble
    toggle_enable();
    data=location&0x0F;             // lower nibble
    toggle_enable();
}


}