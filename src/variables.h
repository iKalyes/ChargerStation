#ifndef _VARIABLES_H
#define _VARIABLES_H

#include <Arduino.h>
#include <lvgl.h>

//INA219//
extern float voltage;
extern float current;
extern float power;
extern lv_timer_t* ina219_timer;
//SEETING SCREEN//
extern uint8_t brightness;
extern uint16_t sleep_time;
extern bool fan_switch;
extern uint8_t free_space;
//ADC ADJUST//
extern float voltage0;
extern float voltage1;
extern float voltage2;
extern float voltage3;
extern float voltage0_adc;
extern float voltage1_adc;
extern float voltage2_adc;
extern float voltage3_adc;
extern lv_timer_t* adc_timer;
//MAIN SCREEN//
extern bool USBC_Switch;
extern bool USBA_Switch;
//FOR WEB AND WEATHER//
extern uint8_t UpdateWeater_Time;
extern uint32_t CityCode;
extern String qWeather_Key;

#endif