#ifndef _INA219_H
#define _INA219_H

#include <Arduino.h>
#include <variables.h>
#include <lvgl.h>
#include "ui/ui.h"
#include <Adafruit_INA219.h>

#define SDA_PIN 21
#define SCL_PIN 22

void ina219_init();
void ina219_task(lv_timer_t *timer);

#endif