#include <variables.h>

//INA219
float voltage = 0.0f;
float current = 0.0f;
float power = 0.0f;
lv_timer_t* ina219_timer = NULL;
//SEETING
uint8_t brightness = 0;
uint16_t sleep_time = 0;
//ADC
float voltage0 = 0.0f;
float voltage1 = 0.0f;
float voltage2 = 0.0f;
float voltage3 = 0.0f;
float voltage0_adc = 10.85f;
float voltage1_adc = 10.85f;
float voltage2_adc = 10.85f;
float voltage3_adc = 10.85f;
lv_timer_t* adc_timer = NULL;