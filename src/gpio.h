#ifndef _GPIO_H
#define _GPIO_H

#include <Arduino.h>
#include <variables.h>

#define TYPE_C 23
#define TYPE_A 27
#define FAN 26

void gpio_init();
void USBA_ON();
void USBA_OFF();
void USBC_ON();
void USBC_OFF();
void FAN_ON();
void FAN_OFF();

#endif