//
// Created by user on 2025/7/8.
//

#ifndef COMMODITY_MANAGER_COMM_OPERATION_H
#define COMMODITY_MANAGER_COMM_OPERATION_H


#include "commodity.h"
#include "stdio.h"

/**
 * 显示所有商品信息
 * @param items
 * @param count
 */
void display_all(Commodity  items[],int count);


/**
 * 从仓库中删除商品
 * @param items
 * @param count
 */
void delete_commodity(Commodity  items[],int *count);


/**
 * 商品排序算法
 * @param items
 * @param count
 */
void sort_commodities(Commodity items[], int count);

/**
 * 修改商品信息
 * @param items
 * @param count
 */
void modify_commodity(Commodity items[], int count);

/**
 * 显示商品总数量
 * @param count
 */
void print_total_count(int count);


/**
 * 检索商品信息
 * @param items
 * @param count
 */
void search_commodity(Commodity items[], int count);


#endif//COMMODITY_MANAGER_COMM_OPERATION_H
