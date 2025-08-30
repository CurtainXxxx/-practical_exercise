//
// Created by user on 2025/7/7.
//

#ifndef COMMODITY_MANAGER_FILE_IO_H
#define COMMODITY_MANAGER_FILE_IO_H

#include "commodity.h"

/**
 * 加载系统配置信息
 */
void load_comm_properties();

/**
 * 添加商品信息到结构体数组
 * @param items
 * @param item
 * @return
 */
ErrorCode add_commodity(Commodity items[], int *count , Commodity item);

/**
 * 保存商品信息到文件中
 * @param items
 * @param count
 * @param filename
 * @return
 */
ErrorCode  save_commodities(Commodity items[], int count, char *filename);


/**
 * 加载历史商品文件数据
 * @param items
 * @param filename
 * @return
 */
int load_comm_data(Commodity items[],char *filename);

#endif//COMMODITY_MANAGER_FILE_IO_H
