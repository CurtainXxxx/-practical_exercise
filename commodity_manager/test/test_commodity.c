//
// Created by user on 2025/7/8.
//
#include "unity.h"
#include "file_io.h"

void setUp(){
    printf("setUp....\n");
}


/**
 * 测试添加商品函数功能的单元测试用例
 */
void test_add_commodity(){
    printf("进入测试添加商品函数功能的单元测试用例!\n");
    Commodity items[10];
    int count = 0;
    Commodity  item = {
            100,"apple",4000.0,10.0,0
    };

    ErrorCode errorCode =  add_commodity(items,&count,item);
    TEST_ASSERT_EQUAL(SUCCESS,errorCode);
    TEST_ASSERT_EQUAL(1,count);
    printf("执行单元测试用例完成!\n");

}

void test_display_all(){

}



void tearDown(){
    printf("tearDown.....\n");
}

#ifndef UNIT_TESTING
/**
 * 测试程序的入口
 * @return
 */
int main(){

    UNITY_BEGIN();
    RUN_TEST(test_add_commodity);
    return UNITY_END();

}
#endif