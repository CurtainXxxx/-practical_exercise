//
// Created by user on 2025/7/7.
//

#include "menu.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "file_io.h"
#include "comm_operation.h"

//全局变量
int count = 0;
//文件数据初始化标记
int flag = 0;


/**
 * 设置字体颜色的函数
 * @param color
 */
void setColor(int color){
   HANDLE hConsole =  GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,color);
}

void display_menu(){
    //清空屏幕内容
    system("cls");
    printf("\n\n");
    setColor(10);
    printf("-------------------商品管理系统V1.0-----------------\n");
    printf("|     0. 退出                                  |\n");
    printf("|     1. 录入商品                               |\n");
    printf("|     2. 查找商品                               |\n");
    printf("|     3. 删除商品                               |\n");
    printf("|     4. 修改商品                               |\n");
    printf("|     5. 排序商品                               |\n");
    printf("|     6. 显示所有商品                            |\n");
    printf("|     7. 统计商品数量                            |\n");
    printf("|------------------------------------------------|\n");
    printf(">>> 请选择功能操作:");

}


int get_user_choice(){
    //输入选择对应功能
    int choice;
    scanf("%d",&choice);
    return choice;
}


int handle_menu_choice(int choice,int load_count, Commodity items[]){
    if(flag == 0){
        count = load_count;
        flag = 1;
    }
    switch (choice) {
        case EXIT:
            break;
        case ADD_COMMODITY:
            printf("进入添加商品模块!\n");
            //添加商品的逻辑
            // 从控制台输入
            Commodity  item;
            printf("请输入商品编号:");
            scanf("%d",&item.id);
            printf("请输入商品名称:");
            scanf("%s",item.name);
            printf("请输入商品价格:");
            scanf("%lf",&item.price);
            printf("请输入商品数量:");
            scanf("%lf",&item.quantity);


            //把商品信息保存到商品结构体
            ErrorCode  errorCode =  add_commodity(items, &count, item);
            if(errorCode == BUFFER_FULL){
                printf("库存已满！\n");
            } else if(errorCode == REPEAT_ID) {
                printf("该商品已经添加！ \n");
            } else {
                printf("商品已经添加成功！ \n");
            }
            break;
        case SEARCH_COMMODITY:
            search_commodity(items,count);
            break;
        case DISPLAY_ALL:
            setColor(14);
            display_all(items,count);
            break;
        case DELETE_COMMODITY:
            delete_commodity(items,&count);
            break;
        case COMMODITY_SORT:
            sort_commodities(items, count);
            break;
        case MODIFY_COMMODITY:
            modify_commodity(items, count);
            break;
        case TOTAL_COUNT:
            print_total_count(count);
            break;
        default:
            printf("无效的选择，请重新输入!!!\n");
            break;
    }

    getchar();
    getchar();
    return count;
}
