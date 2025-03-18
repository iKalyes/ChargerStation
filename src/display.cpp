#include <display.h>

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp_drv );
}

void backlight_init()
{
    ledcSetup(0, 1000, 8);
    ledcAttachPin(TFT_BL, 0); //backlight control
    ledcWrite(0, 255); //turn on backlight
}

void backlight_set( uint8_t brightness )
{
    ledcWrite(0, brightness);
}

void display_init()
{
    lv_init();

    tft.begin();          /* TFT init */
    tft.fillScreen( TFT_BLACK ); /* Fill the screen with black */
    tft.setRotation( 0 ); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );
    
    ui_init(); /* Initialize the UI */
    backlight_init(); /* Initialize the backlight */
    style_init(); /* Initialize the focus style */
}

void display_task()
{
    lv_task_handler(); /* let the GUI do its work */
}

void style_init()
{
    lv_obj_set_style_outline_color(ui_USBCSwitch, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_USBCSwitch, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBASwitch, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_USBASwitch, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_Setting, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_Setting, 3, LV_STATE_FOCUS_KEY);
    
    lv_obj_set_style_outline_color(ui_WiFiWebPage, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_WiFiWebPage, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ADCAdjust, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_ADCAdjust, 2, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_FanSwitch, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_FanSwitch, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SliderSleepTime, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SliderSleepTime, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_SliderSleepTime, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SliderBrightness, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_SliderBrightness, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_SliderBrightness, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_Back, lv_color_hex(0xffff00), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_Back, 3, LV_STATE_FOCUS_KEY);

    lv_obj_set_style_outline_color(ui_USBAAdjust, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBAAdjust, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_USBAAdjust, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC3Adjust, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC3Adjust, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_USBC3Adjust, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC2Adjust, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC2Adjust, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_USBC2Adjust, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC1Adjust, lv_color_hex(0xffffff), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_USBC1Adjust, lv_color_hex(0xffff00), LV_STATE_EDITED);
    lv_obj_set_style_outline_width(ui_USBC1Adjust, 3, LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ADCBack, lv_color_hex(0xffff00), LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_width(ui_ADCBack, 3, LV_STATE_FOCUS_KEY);
}
