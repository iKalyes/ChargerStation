#ifndef _FLASH_H_
#define _FLASH_H_

#include "ui/ui.h"

#include <Preferences.h>
#include <Arduino.h>
#include <variables.h>
#include <gpio.h>
#include <lvgl.h>

void get_free_space();
void save_setting();
void load_setting();
void save_USBA_setting();
void save_USBC_setting();
void save_adc_setting();

void flash_init();

#endif