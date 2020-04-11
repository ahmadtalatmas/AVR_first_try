/*
 * File:   IODrivers.c
 * Author: Ahmad
 *
 * Created on April 10, 2020, 9:08 PM
 */


#include <xc.h>

int isPressedA(int pinNum) {
    if (PINA & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedB(int pinNum) {
    if (PINB & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedC(int pinNum) {
    if (PINC & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedD(int pinNum) {
    if (PIND & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
//setPIN(LED, portA);

void setPIN(int pinNum, char port) {

    switch (port) {

        case 1:
            PORTA |= (1 << pinNum);
            break;
        case 2:
            PORTB |= (1 << pinNum);
            break;
        case 3:
            PORTC |= (1 << pinNum);
            break;
        case 4:
            PORTD |= (1 << pinNum);
            break;
    }

}

void resetPIN(int pinNum, char port) {

    switch (port) {

        case 1:
            PORTA &= ~(1 << pinNum);
            break;
        case 2:
            PORTB &= ~(1 << pinNum);
            break;
        case 3:
            PORTC &= ~(1 << pinNum);
            break;
        case 4:
            PORTD &= ~(1 << pinNum);
            break;
    }

}

void pinAas(int pinNum, int dir) {

    switch (dir) {
        case 1:
            DDRA |= (1 << pinNum);
            break;
        case 0:
            DDRA &= ~(1 << pinNum);

    }
}
void pinBas(int pinNum, int dir) {

    switch (dir) {
        case 1:
            DDRB |= (1 << pinNum);
            break;
        case 0:
            DDRB &= ~(1 << pinNum);

    }
}
void pinCas(int pinNum, int dir) {

    switch (dir) {
        case 1:
            DDRC |= (1 << pinNum);
            break;
        case 0:
            DDRC &= ~(1 << pinNum);

    }
}
void pinDas(int pinNum, int dir) {

    switch (dir) {
        case 1:
            DDRD |= (1 << pinNum);
            break;
        case 0:
            DDRD &= ~(1 << pinNum);

    }
}

void setPINA(int pinNum) {
    PORTA |= (1 << pinNum);
}

void resetPINA(int pinNum) {
    PORTA &= ~(1 << pinNum);
}

void setPINB(int pinNum) {
    PORTB |= (1 << pinNum);
}

void setPINC(int pinNum) {
    PORTC |= (1 << pinNum);
}

void setPIND(int pinNum) {
    PORTD |= (1 << pinNum);
}

void setPORT(char port) {
    switch (port) {
        case 1:
            PORTA = 0xFF;
            break;
        case 2:
            PORTB = 0xFF;
            break;
        case 3:
            PORTC = 0xFF;
            break;
        case 4:
            PORTD = 0xFF;
            break;

    }

}

void resetPORT(char port) {
    switch (port) {
        case 1:
            PORTA = 0x00;
            break;
        case 2:
            PORTB = 0x00;
            break;
        case 3:
            PORTC = 0x00;
            break;
        case 4:
            PORTD = 0x00;
            break;

    }

}



