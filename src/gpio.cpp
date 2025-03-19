#include <gpio.h>

void gpio_init()
{
      pinMode(TYPE_C, OUTPUT);
      pinMode(TYPE_A, OUTPUT);
      digitalWrite(TYPE_C, LOW);
      digitalWrite(TYPE_A, LOW);

      ledcSetup(1, 1000, 8);
      ledcAttachPin(FAN, 1);
      ledcWrite(1, 0); 
}

void USBA_ON()
{
    USBA_Switch = true;
    digitalWrite(TYPE_A, HIGH);
}

void USBA_OFF()
{
    USBA_Switch = false;
    digitalWrite(TYPE_A, LOW);
}

void USBC_ON()
{
    USBC_Switch = true;
    digitalWrite(TYPE_C, HIGH);
}

void USBC_OFF()
{
    USBC_Switch = false;
    digitalWrite(TYPE_C, LOW);
}

void FAN_ON()
{
    ledcWrite(1, 255);
    fan_switch = true;
}

void FAN_OFF()
{
    ledcWrite(1, 0);
    fan_switch = false;
}