#ifndef _VARIABLES_H
#define _VARIABLES_H

#include <Arduino.h>
#include <lvgl.h>

//INA219
extern float voltage;
extern float current;
extern float power;
extern lv_timer_t* ina219_timer;
//SEETING
extern uint8_t brightness;
extern uint16_t sleep_time;
//ADC
extern float voltage0;
extern float voltage1;
extern float voltage2;
extern float voltage3;
extern float voltage0_adc;
extern float voltage1_adc;
extern float voltage2_adc;
extern float voltage3_adc;
extern lv_timer_t* adc_timer;

#endif