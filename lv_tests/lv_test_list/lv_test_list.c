/**
 * @file lv_test_list.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_test_list.h"

#if USE_LV_LIST != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_res_t list_move(lv_obj_t *btn);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *list1;
static lv_obj_t *list2;
static lv_obj_t *list3;
static lv_obj_t *list4;

LV_IMG_DECLARE(img_flower_icon);

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a default object and test the basic functions
 */
void lv_test_list_1(void)
{
    /* Default object. It will be an empty list*/
    list1 = lv_list_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(list1, 10, 10);

    lv_img_create_file("icon", img_flower_icon);
    list2 = lv_list_create(lv_scr_act(), NULL);
    lv_obj_align_scale(list2, list1, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
    lv_list_add(list2, symbol_file, "File", NULL);
    lv_list_add(list2, symbol_directory, "Directory", NULL);
    lv_list_add(list2, "U:icon", "Image icon", NULL);
    lv_obj_set_width_scale(list2, 100);

    list3 = lv_list_create(lv_scr_act(), list2);
    lv_obj_align_scale(list3, list2, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
    lv_list_add(list3, "", "No icon", NULL);
    lv_list_add(list3, symbol_close, "", NULL);
    lv_list_add(list3, symbol_up, "Up", NULL);
    lv_list_add(list3, symbol_down, "Down", NULL);

    static lv_style_t sb;
    static lv_style_t bg;
    lv_style_copy(&sb, &lv_style_pretty_color);
    lv_style_copy(&bg, &lv_style_pretty_color);
    sb.body.padding.hor = -10 << LV_ANTIALIAS;
    sb.body.padding.inner = 10 << LV_ANTIALIAS;

    bg.body.padding.hor = 20 << LV_ANTIALIAS;

    list4 = lv_list_create(lv_scr_act(), list3);
    lv_list_set_style(list4, &bg, NULL, &sb);
    lv_obj_align_scale(list4, list3, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
    lv_obj_set_width_scale(list4, 200);


    /*Add list up/down buttons*/
    lv_obj_t *btn_up = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_align_scale(btn_up, list1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_btn_set_action(btn_up, LV_BTN_ACTION_RELEASE, list_move);
    lv_obj_set_free_num(btn_up, 0);
    lv_obj_t *label = lv_label_create(btn_up, NULL);
    lv_label_set_text(label, symbol_up);

    lv_obj_t *btn_down = lv_btn_create(lv_scr_act(), btn_up);
    lv_obj_align_scale(btn_down, btn_up, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_set_free_num(btn_down, 1);
    label = lv_label_create(btn_down, NULL);
    lv_label_set_text(label, symbol_down);

}



/**********************
 *   STATIC FUNCTIONS
 **********************/

static lv_res_t list_move(lv_obj_t *btn)
{
    if(lv_obj_get_free_num(btn) == 0) {
        lv_list_up(list1);
        lv_list_up(list2);
        lv_list_up(list3);
        lv_list_up(list4);
    } else {
        lv_list_down(list1);
        lv_list_down(list2);
        lv_list_down(list3);
        lv_list_down(list4);
    }
    return LV_RES_OK;
}

#endif /*USE_LV_LIST*/