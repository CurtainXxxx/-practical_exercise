//
// Created by user on 2025/7/4.
//

#ifndef COMMODITY_MANAGER_COMMODITY_H
#define COMMODITY_MANAGER_COMMODITY_H

#define NAME_LEN 20
#define MAX_COMMODITIES 100
#define DATA_FILE "../data/comm_file.dat"

#define DISPLAY_LINE "-----------------------------------------------------\n"

/**
 * 商品信息数据结构
 */
typedef struct {
    //商品ID
    int id;
    //商品名称
    char name[NAME_LEN];
    //商品价格
    double price;
    //商品数量
    double quantity;
    //总价
    double total_value;

} Commodity;


/**
 * 状态码
 */
typedef enum{
    SUCCESS,
    FAIL,
    FILE_OPEN_ERROR = 0,
    FILE_WRITE_ERROR,
    INVALID_INPUT,
    BUFFER_FULL,
    REPEAT_ID
} ErrorCode;


typedef enum {
    EXIT,
    ADD_COMMODITY,
    SEARCH_COMMODITY,
    DELETE_COMMODITY,
    MODIFY_COMMODITY,
    COMMODITY_SORT = 5,
    DISPLAY_ALL = 6,
    TOTAL_COUNT
} MenuOption;

#endif//COMMODITY_MANAGER_COMMODITY_H
