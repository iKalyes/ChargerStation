#ifndef _LVGL_EVENT_H
#define _LVGL_EVENT_H

#define TYPE_C 23
#define TYPE_A 27
#define FAN 26

#include "ui/ui_helpers.h"
#include "ui/ui_events.h"
#include "ui/ui_theme_manager.h"
#include "ui/ui_themes.h"

#include <Arduino.h>
#include <lvgl.h>
#include <display.h>
#include <variables.h>
#include <lvgl_group.h>

void gpio_init();

#endif