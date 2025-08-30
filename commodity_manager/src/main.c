
#include "file_io.h"
#include "menu.h"
#include "commodity.h"
#include <stdio.h>


//条件编译
//#ifndef UNIT_TESTING

/**
 * 主程序入库
 * @return
 */
int main() {

    //定义商品的结构体变量
    Commodity items[MAX_COMMODITIES];

    //加载系统配置信息
    load_comm_properties();
    //记录记载文件中商品的数量

    //加载文件数据
    int comm_count = load_comm_data(items,DATA_FILE);

    //显示主菜单
    MenuOption choice;

    do{
        display_menu();
        choice =  get_user_choice();
        int count = handle_menu_choice(choice,comm_count,items);

        //保存结构体数组 数据到文件中
        if(choice == ADD_COMMODITY || choice == DELETE_COMMODITY || choice == MODIFY_COMMODITY){
            save_commodities(items,count,DATA_FILE);
        }
    } while(choice != EXIT);

    return 0;
}

//#endif