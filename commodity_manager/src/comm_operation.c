//
// Created by user on 2025/7/8.
//
#include "commodity.h"
#include "comm_operation.h"
#include "string.h"


/**
 * 要完成功能是一块独立的功能，高内聚性，低耦合性
 * @param items
 * @param count
 */
void display_all(Commodity items[], int count) {
    printf("进入商品显示模块! \n");
    //items 是否有商品
    if (count == 0) {
        printf("没有库存信息！！！\n");
        return;
    }

    //显示商品信息
    printf("编号     商品名称      单价       数量      总金额 \n");
    printf(DISPLAY_LINE);
    for (int i = 0; i < count; ++i) {
        printf("%d   %s   %lf  %lf  %lf  \n", items[i].id, items[i].name, items[i].price, items[i].quantity,
               items[i].total_value);
        printf(DISPLAY_LINE);
    }
}


/**
 * 从仓库中删除商品
 * @param items
 * @param count
 */
void delete_commodity(Commodity items[], int *count) {

    if (*count == 0) {
        printf("库存信息为空!");
        return;
    }
    //第二步 输入删除的商品ID
    int id;
    printf("请输入删除的商品ID:");
    scanf("%d", &id);

    //第三步 删除商品
    //3.1 找到数组下标位置
    int index = -1;
    for (int i = 0; i < *count; ++i) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("无效的商品ID\n");
        return;
    }
    getchar();
    getchar();
    printf("确认删除 %s 吗?(Y/y):", items[index].name);
    char confirm;
    scanf("%c", &confirm);
    if (confirm == 'Y' || confirm == 'y') {
        for (int i = index; i < (*count + 1); ++i) {
            items[i] = items[i + 1];
        }
        (*count)--;
        printf("%d 商品信息删除成功!\n", id);
    } else {
        printf("取消删除！\n");
    }
    //3.2 覆盖，count数量更新一下
}

int get_sort_choice() {
    printf("1. 按照ID排序\n");
    printf("2. 按照单价来排序\n");
    printf("3. 按照总价排序\n");
    printf("请输入选择的排序方式:");
    int choice;
    scanf("%d", &choice);
    return choice;
}

/**
 *
 * @param items
 * @param count
 */
void sort_commodities(Commodity items[], int count) {

    int choice = get_sort_choice(); // 获取用户排序选择

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int need_swap = 0;

            switch (choice) {
                case 1: // 按ID升序
                    need_swap = items[i].id > items[j].id;
                    break;
                case 2: // 按单价降序
                    need_swap = items[i].price < items[j].price;
                    break;
                case 3: // 按总价值降序
                    need_swap = items[i].total_value < items[j].total_value;
                    break;
            }
            if (need_swap) {
                Commodity temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    display_all(items, count);
}

/**
 * 修改商品信息
 * @param items
 * @param count
 */
void modify_commodity(Commodity items[], int count) {

    // 判断仓库是否商品
    if (count == 0) {
        printf("仓库没有商品!\n");
        return;
    }
    //2 输入商品ID，找到商品信息
    int id;
    printf("请输入要修改的商品ID：");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("没有找到修改的商品ID%d! \n", id);
    }
    //3修改商品名称 。。。。

    printf("修改的当前商品信息!\n");
    printf("编号     商品名称      单价       数量      总金额 \n");
    printf(DISPLAY_LINE);
    printf("%d   %s   %lf  %lf  %lf  \n", items[index].id, items[index].name, items[index].price, items[index].quantity,
           items[index].total_value);
    printf(DISPLAY_LINE);

    printf("请输入要修改的商品名称:");
    char new_name[NAME_LEN];
    getchar();
    fgets(new_name,NAME_LEN,stdin);
    new_name[strcspn(new_name,"\n")] = '\0';
    strncpy(items[index].name, new_name, NAME_LEN-1);

    //任务： 修改价格 ，数量


    printf("修改商品成功!");

}

/**
 * 输出商品总数
 * @param count
 */
void print_total_count(int count) {
    //输出之前可以 通过count 与结构体数组进行校验，确保一致后在输出！
    printf("仓库商品总数为： %d \n", count );
}


void search_commodity(Commodity items[], int count){
    // 判断仓库是否商品
    if (count == 0) {
        printf("仓库没有商品!\n");
        return;
    }
    int id;
    printf("请输入要检索的商品ID:");
    scanf("%d",&id);
    for (int i = 0; i < count; ++i) {
        if(items[i].id == id) {
            printf("编号     商品名称      单价       数量      总金额 \n");
            printf(DISPLAY_LINE);
            printf("%d   %s   %lf  %lf  %lf  \n", items[i].id, items[i].name, items[i].price, items[i].quantity,
                   items[i].total_value);
            printf(DISPLAY_LINE);
        }
        break;
    }
}