/*
 * File:   UART_Driver.c
 * Author: Ahmad
 *
 * Created on June 28, 2020, 2:58 PM
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


void UART_Init_Transmit_Receive();
void transmitString(char string[]);
char data;
void UART_init();
void SPI_Master_Init();
void SPI_Master_Transmit(char data);

ISR(USART_RXC_vect) {

    data = UDR;
    SPI_Master_Transmit(data);
}

int main(void) {
    SPI_Master_Init();
    sei();
    UART_Init_Transmit_Receive(9600);
    DDRD |= (1 << 2);
    while (1) {


    }


}

void UART_Init_Transmit_Receive(int baudRate) {
    int UBRR_value;
    UCSRB |= (1 << RXEN);
    UCSRB |= (1 << RXCIE);
    UCSRB |= (1 << TXEN);
    UBRR_value = (F_CPU / (16.0 * baudRate)) - 1;
    if (UBRR_value <= 255)
        UBRRL = (char) (UBRR_value);
    else {
        UBRRL = (char) (UBRR_value);
        UBRRH = (char) (UBRR_value >> 8);
    }
}

void transmitString(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        while (!(UCSRA & (1 << UDRE)));
        UDR = string[i];
        i++;
    }

}

void SPI_Master_Init() {
    DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_Master_Transmit(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));

}