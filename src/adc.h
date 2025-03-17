#ifndef _ADC_H
#define _ADC_H

#define ADC0_PIN 35
#define ADC1_PIN 34
#define ADC2_PIN 36
#define ADC3_PIN 39

#include <Arduino.h>
#include <variables.h>
#include <lvgl.h>
#include "ui/ui.h"

void adc_init();
void adc_task(lv_timer_t *timer);

#endif
