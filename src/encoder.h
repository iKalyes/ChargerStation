#ifndef _ENCODER_H
#define _ENCODER_H

#include <Arduino.h>
#include <RotaryEncoder.h>
#include <variables.h>
#include <lvgl.h>
#include "ui/ui.h"

IRAM_ATTR void encoder_tick();  // Interrupt Service Routine for the encoder
void encoder_init();
void encoder_lvgl_init();
lv_indev_t* get_encoder_indev();

#endif