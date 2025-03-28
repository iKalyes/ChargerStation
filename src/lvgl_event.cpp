#include <lvgl_event.h>

void ui_event_USBCSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBCPowerON( e );
      USBC_ON();
      save_USBC_setting();
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBCPowerOFF( e );
      USBC_OFF();
      save_USBC_setting();
}
}

void ui_event_USBASwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBAPowerON( e );
      USBA_ON();
      save_USBA_setting();
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      USBAPowerOFF( e );
      USBA_OFF();
      save_USBA_setting();
}
}

void ui_event_Setting( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_SettingScreen_screen_init);
      lvgl_group_to_setting();
}
}

void ui_event_Weather( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_WeatherScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_WeatherScreen_screen_init);
      lvgl_group_to_weather();
}
}

void ui_event_ADCAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_ADCAdjustScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_ADCAdjustScreen_screen_init);
        lvgl_group_to_adc();
    }
}

void ui_event_FanSwitch( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      FanSwitchON( e );
      FAN_ON();
}
if ( event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target,LV_STATE_CHECKED)  ) {
      FanSwitchOFF( e );
      FAN_OFF();
}
}

void ui_event_SliderSleepTime( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);

if ( event_code == LV_EVENT_VALUE_CHANGED) {
      _ui_slider_set_text_value( ui_SleepTime, target, "", "M");
      sleep_time = lv_slider_get_value(target);
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
      _ui_screen_change( &ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_MainScreen_screen_init);
      lvgl_group_to_main();
      save_setting();
}
}

void ui_event_USBAAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        USBAAdjust(e);
        voltage0_adc = (float)(lv_slider_get_value(ui_USBAAdjust)) * 0.01f;
    }
}

void ui_event_USBC3Adjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        USBC3Adjust(e);
        voltage1_adc = (float)(lv_slider_get_value(ui_USBC3Adjust)) * 0.01f;
    }
}

void ui_event_USBC2Adjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        USBC2Adjust(e);
        voltage2_adc = (float)(lv_slider_get_value(ui_USBC2Adjust)) * 0.01f;
    }
}

void ui_event_USBC1Adjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        USBC1Adjust(e);
        voltage3_adc = (float)(lv_slider_get_value(ui_USBC1Adjust)) * 0.01f;
    }
}

void ui_event_ADCBack(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_SettingScreen_screen_init);
        lvgl_group_to_setting();
        save_adc_setting();
    }
}

void ui_event_WiFiWebPage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_WiFiScreen, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_WiFiScreen_screen_init);
        lvgl_group_to_wifi();
    }
}

void ui_event_WIFIStart(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        WIFIStart(e);
        wificonfig_flag = true;
    }
}

void ui_event_WIFIReset(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        WIFIResrt(e);
        wifireset();
    }
}

void ui_event_WIFIBack(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_SettingScreen_screen_init);
        lvgl_group_to_setting();
    }
}

void ui_event_WeatherBack( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_MainScreen_screen_init);
      lvgl_group_to_main();
}
}

void ui_event_WeatherSetting( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_PRESSED) {
      _ui_screen_change( &ui_SettingScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_SettingScreen_screen_init);
      lvgl_group_to_setting();
}
}