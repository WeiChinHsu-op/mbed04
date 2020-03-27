#include "LCD.h"

int main()
{
    LCD_init();
    display_to_LCD(0x48);
    display_to_LCD(0x45);
    display_to_LCD(0x4C);
    display_to_LCD(0x4C);
    display_to_LCD(0x4F);
    for(char x=0x30;x<=0x39;x++)
    {
        display_to_LCD(x);      // display numbers 0-9
    }

}