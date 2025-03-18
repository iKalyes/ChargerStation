#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include "ui/ui.h"
#include <variables.h>

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p );
void backlight_init();
void backlight_set( uint8_t brightness );
void display_init();
void display_task();
void style_init();

#endif