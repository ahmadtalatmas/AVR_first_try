/*
 * File:   main.c
 * Author: Ahmad
 *
 * Created on April 10, 2020, 9:07 PM
 */


#include <avr/io.h>
#include "IODrivers.h"
#include "BoardConfig.h"
#include "lcd.h"
#define portA           1
#define portB           2
#define portC           3
#define portD           4
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

int main(void) {

    // Data Direction Register
    DDRA = 0x00;
    DDRA |= (1 << relay);
    DDRC = 0xFF;
    PORTC = 0x00;
    DDRB = 0x00; // INPUT PIN.
    DDRD = 0x00;
    DDRD |= (1 << LED2);
    
    LCD_Init();
    char a[] = "LED 1 is ON";
    char b[] = "LED 2 is ON";
    char c[] = "LED 3 is ON";
    char d[] = "LED 1 is OFF";
    char e[] = "LED 2 is OFF";
    char f[] = "LED 3 is OFF";

    while (1) {
        // Loop until power OFF
        if (isPressedB(button0)) {
            _delay_ms(100);
            if (isPressedB(button0)) {
                togglePINC(LED0);
                LCD_Clear();
                flag1 += 1;
                if (flag1 == 1)
                    LCD_String(a);
                else {
                    flag1 = 0;
                    LCD_String(d);
                }
            }
        }
        if (isPressedB(button1)) {
            _delay_ms(100);
            if (isPressedB(button1)) {
                togglePINC(LED1);
                LCD_Clear();
                flag2 += 1;
                if (flag2 == 1)
                    LCD_String(b);
                else {
                    flag2 = 0;
                    LCD_String(e);
                }
            }
        }
        if (isPressedD(button2)) {
            _delay_ms(100);
            if (isPressedD(button2)) {
                togglePIND(LED2);
                LCD_Clear();
                flag3 += 1;
                if (flag3 == 1)
                    LCD_String(c);
                else {
                    flag3 = 0;
                    LCD_String(f);
                }
            }
        }
    }
}
