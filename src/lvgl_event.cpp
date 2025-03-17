#include <lvgl_event.h>

void gpio_init()
{
      pinMode(TYPE_C, OUTPUT);
      pinMode(TYPE_A, OUTPUT);
      digitalWrite(TYPE_C, HIGH);
      digitalWrite(TYPE_A, HIGH);
}

void ui_event_USBCSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBCPowerON( e );
      digitalWrite(TYPE_C, HIGH);
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBCPowerOFF( e );
      digitalWrite(TYPE_C, LOW);
}
}

void ui_event_USBASwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBAPowerON( e );
      digitalWrite(TYPE_A, HIGH);
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBAPowerOFF( e );
      digitalWrite(TYPE_A, LOW);
}
}

void ui_event_Setting( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_SettingScreen_screen_init);
}
}

void ui_event_FanSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      FanSwitchON( e );
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      FanSwitchOFF( e );
}
}

void ui_event_PwControl( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      PwControlON( e );
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      PwControlOFF( e );
}
}

void ui_event_SliderSleepTime( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_slider_set_text_value( ui_SleepTime, target, "", "M");
}
}

void ui_event_SliderBrightness( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_slider_set_text_value( ui_Brightness, target, "", "%");
      int slider_value = lv_slider_get_value(target);
      brightness = (uint8_t)(slider_value * 2.55f + 0.5f); // 加0.5是为了四舍五入
      backlight_set(brightness);
}
}

void ui_event_Back( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_MainScreen_screen_init);
}
}
