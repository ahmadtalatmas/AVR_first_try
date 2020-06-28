/*
 * File:   SPI_Receive.c
 * Author: Ahmad
 *
 * Created on June 28, 2020, 8:40 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#define MISO 6
#define MOSI 5
#define SCK 7
#define SS 4

char x;

void SPI_Slave_Init() {
    DDRB |= (1 << MISO);
    SPCR |= (1 << SPE) | (1 << SPR0);
}

char SPI_Slave_Receive() {
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

int main(void) {
    SPI_Slave_Init();
    DDRC = 0xFF;

    while (1) {
        x = SPI_Slave_Receive();
        if (x == 'O')
            PORTC |= (1 << 0 );
        else if (x == 'F')
            PORTC &= ~(1 << 0);
    }
}
