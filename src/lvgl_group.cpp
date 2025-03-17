#include <lvgl_group.h>

void lvgl_group_init()
{
    lv_group_t* group = lv_group_create();
    lv_group_set_default(group);
    lv_indev_set_group(get_encoder_indev(), group);

    lv_group_add_obj(group, ui_USBCSwitch);
    lv_group_add_obj(group, ui_USBASwitch);
    lv_group_add_obj(group, ui_Setting);

    lv_group_add_obj(group, ui_WiFiWebPage);
    lv_group_add_obj(group, ui_FanSwitch);
    lv_group_add_obj(group, ui_PwControl);
    lv_group_add_obj(group, ui_SliderSleepTime);
    lv_group_add_obj(group, ui_SliderBrightness);
    lv_group_add_obj(group, ui_Back);
}