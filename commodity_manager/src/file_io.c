//
// Created by user on 2025/7/7.
//

#include "file_io.h"
#include "commodity.h"
#include "stdio.h"


void load_comm_properties(){


}


/**
 * 函数传参数： 传地址， 传值
 * @param items
 * @param count
 * @param item
 * @return
 */
ErrorCode add_commodity(Commodity items[], int *count, Commodity item){
    //items 是否还能添加
    if(*count >= MAX_COMMODITIES ){
        return BUFFER_FULL;
    }

    //校验一下商品ID是否存在
    for (int i = 0; i < *count; ++i) {
        if(items[i].id == item.id){
            return REPEAT_ID;
        }
    }
    //计算一下总额
    item.total_value = item.price * item.quantity;

    //添加到商品结构体数组
    items[*count] = item;
    (*count)++;
    return SUCCESS;

}


ErrorCode  save_commodities(Commodity items[], int count, char *filename){
    printf("进入文件写入函数! %d \n", count);
    //第一步： 打开文件，  wb
    FILE *fp = fopen(filename,"wb");
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }

    //第二步： 保存数据
    for (int i = 0; i < count; ++i) {
        //商品结构体数据保存到文件中， 如果返回1代表保存成功
        if(fwrite(&items[i],sizeof(Commodity),1,fp) != 1){
            fclose(fp);
            return FILE_WRITE_ERROR;
        }
    }
    //第三步 ： 关闭文件
    fclose(fp);
    return SUCCESS;
}


int load_comm_data(Commodity items[],char *filename) {
    //第一步： 打开文件
    FILE *fp = fopen(filename,"rb");
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }
    //第二步： 读文件数据，给到items数组
    int count = 0;
    while(fread(&items[count],sizeof(Commodity),1,fp) == 1){
        count ++;
    }
    //第三步：关闭文件，返回加载商品数量
    fclose(fp);
    return count;
}

