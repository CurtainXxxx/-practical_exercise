//
// Created by user on 2025/7/7.
//

#ifndef COMMODITY_MANAGER_MENU_H
#define COMMODITY_MANAGER_MENU_H

#include "commodity.h"

/**
 * 显示系统主菜单
 */
void display_menu();

/**
 * 获取用户选择的功能
 */
int get_user_choice();

/**
 * 功能菜单选择模块
 * @param choice
 * @param load_count  从文件中加载的商品数量
 * @param items
 * @return int
 */
int handle_menu_choice(int choice, int load_count, Commodity items[]);

#endif//COMMODITY_MANAGER_MENU_H
