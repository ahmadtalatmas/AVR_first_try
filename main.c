/*
 * File:   main.c
 * Author: Ahmad
 *
 * Created on April 10, 2020, 9:07 PM
 */


#include <avr/io.h>
#include "IODrivers.h"
#include "BoardConfig.h"


#define portA           1
#define portB           2
#define portC           3
#define portD           4

int main(void) {

    // Data Direction Register
    DDRA = 0x00;
    DDRA |= (1 << relay);
    DDRC = 0xFF;
    PORTC = 0x00;
    DDRB = 0x00; // INPUT PIN.
    DDRD = 0x00;
    DDRD |= (1 << LED2);

    while (1) {
        // Loop until power OFF
        if (isPressedB(button0))
            setPIN(LED0, portC);
        else
            resetPIN(LED0, portC);
        if (isPressedB(button1)) {
            setPIN(LED1, portC);
            setPINA(buzzer);

        } else {
            resetPIN(LED1, portC);
            resetPINA(buzzer);
        }
        if (isPressedD(button2))
            setPIN(LED2, portD);
        else
            resetPIN(LED2, portD);

    }
}
