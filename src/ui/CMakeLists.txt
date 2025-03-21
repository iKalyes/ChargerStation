SET(SOURCES screens/ui_MainScreen.c
    screens/ui_SettingScreen.c
    screens/ui_ADCAdjustScreen.c
    screens/ui_WiFiScreen.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_426970754.c
    images/ui_img_2092987087.c
    images/ui_img_1671917170.c
    images/ui_img_1222334931.c
    images/ui_img_1338783594.c
    images/ui_img_175199537.c
    images/ui_img_593743026.c
    images/ui_img_155116563.c
    images/ui_img_2103744591.c
    images/ui_img_123890670.c
    images/ui_img_763584403.c
    images/ui_img_852573520.c
    images/ui_img_1093450328.c
    images/ui_img_2003059303.c
    fonts/ui_font_ASCII20MONO.c
    fonts/ui_font_ASCII32MONO.c
    fonts/ui_font_ASCII40MONO.c)

add_library(ui ${SOURCES})
