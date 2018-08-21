//
//  arr_01.c
//  数组
//
//  Created by 周冰烽 on 2018/8/16.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>//包含关键字bool
#include <stdlib.h>//包含exit和malloc函数

//定义了一个数据类型,该数据类型的名字叫做NSArray,分别是pBase,len,cnt
struct NSArray {
    int *pBase;//存储的是数组第一个元素的地址
    int len;//数组所能容纳最大元素的个数
    int cnt;//当前数组有效元素的个数
//    int increment;//自动增长因子
};

//放大招之前要先喊名字(函数声明)

void init(struct NSArray *pArr,int length);
bool add_object(struct NSArray *pArr,int value);
bool insert_object(struct NSArray *pArr,int pos,int value);
bool delete_object(struct NSArray *pArr,int pos,int *pVal);
bool get(struct NSArray *pArr,int pos,int *pVal);
bool is_empty(struct NSArray *pArr);
bool is_full(struct NSArray *pArr);
void sort_arr(struct NSArray *pArr);
void show_arr(struct NSArray *pArr);
void invert_arr(struct NSArray *pArr);

int main(void){
    struct NSArray array;
    
    int val;

    init(&array,10);
    
    show_arr(&array);
    
    add_object(&array, 21);
    add_object(&array, 546);
    add_object(&array, 2189);
    add_object(&array, 2);
    add_object(&array, 75638);
    
    insert_object(&array, 3, 1000);
    
    show_arr(&array);
    
    if(delete_object(&array, 2,&val)){
        printf("删除成功\n");
        printf("删除的元素是:%d\n",val);
    }else{
        printf("删除失败\n");
    }
    
    show_arr(&array);
    
    if(get(&array, 3, &val)){
        printf("下标为3的元素的值是:%d\n",val);
    }
    
    invert_arr(&array);
    printf("-----倒置-----\n");
    show_arr(&array);
    
    sort_arr(&array);
    printf("-----排序-----\n");
    show_arr(&array);
    
    return 0;
}

/**
 数组初始化
 
 @param pArr 数组的地址
 */
void init(struct NSArray *pArr,int length){
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (pArr->pBase != NULL) {
        pArr->len = length;
        pArr->cnt = 0;
    }else{
        printf("动态内存分配失败");
        exit(-1);//终止整个程序
    }
    return;//函数终止
}

/**
 打印数组元素
 
 @param pArr 数组的地址
 */
void show_arr(struct NSArray *pArr){
    if (is_empty(pArr)) {
        printf("数组为空\n");
    }
    for (int i = 0; i < pArr->cnt; i++) {
        if (i == pArr->cnt -1) {
            printf("%d\n",pArr->pBase[i]);
        }else{
            printf("%d,",pArr->pBase[i]);
        }
    }
}

/**
 判断数组是否为空
 
 @param pArr 数组地址
 @return true | false
 */
bool is_empty(struct NSArray *pArr){
    if (pArr->cnt == 0) {
        return true;
    }
    return false;
}

/**
 判断数组是否已经存满了
 
 @param pArr 数组地址
 @return true | false
 */
bool is_full(struct NSArray *pArr){
    if (pArr->cnt == pArr->len) {
        return true;
    }
    return false;
}


/**
 数组最后一位添加元素
 
 @param pArr 数组地址
 @param value 添加的值
 @return true | false
 */
bool add_object(struct NSArray *pArr,int value){
    if (is_full(pArr)) {
#warning 将修改
        return false;
    }else{
        pArr->pBase[pArr->cnt] = value;
        pArr->cnt++;
        return true;
    }
}


/**
 在具体位置插入元素
 
 @param pArr 数组地址
 @param pos 数组下标
 @param value 具体插入的值
 @return true | false
 */
bool insert_object(struct NSArray *pArr,int pos,int value){
    if (is_full(pArr)) {
        printf("数组已满,插入失败\n");
        return false;
    }else if(pos > 0 && pos < pArr->cnt-1){
        for (int i = pArr->cnt; i >= pos; i--) {
            pArr->pBase[i] = pArr->pBase[i-1];
        }
        pArr->pBase[pos] = value;
        pArr->cnt++;
        printf("插入成功\n");
        return true;
    }else{
        printf("数组越界,插入失败\n");
        return false;
    }
}


/**
 删除某个元素

 @param pArr 数组地址
 @param pos 删除元素的下标
 @param pVal 删除元素的地址
 @return true | false
 */
bool delete_object(struct NSArray *pArr,int pos,int *pVal){
    if (is_empty(pArr)) {
        return false;
    }
    if (pos < 0 || pos > pArr->cnt - 1) {
        return false;
    }
    *pVal = pArr->pBase[pos];
    for (int i = pos; i < pArr->cnt - 1; i++) {
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    pArr->cnt--;
    return true;
}

/**
 获取数组具体下标的元素值

 @param pArr 数组地址
 @param pos 下标
 @param pVal 获取到的值
 @return true | false
 */
bool get(struct NSArray *pArr,int pos,int *pVal){
    if (is_empty(pArr)) {
        printf("数组为空\n");
        return false;
    }
    if (pos < 0 || pos > pArr->cnt-1) {
        printf("pos越界");
        return false;
    }
    
    *pVal = pArr->pBase[pos];
    
    return true;
}


/**
 数组倒序

 @param pArr 数组地址
 */
void invert_arr(struct NSArray *pArr){
    int i = 0;
    int j = pArr->cnt - 1;
    while (i < j) {
        int temp = pArr->pBase[j];
        pArr->pBase[j] = pArr->pBase[i];
        pArr->pBase[i] = temp;
        i++;
        j--;
    }
    return;
}

//冒泡排序 实现排序
void sort_arr(struct NSArray *pArr){
    int i,j;
    for (i = 0; i < pArr->cnt; i++) {
        for (j = i + 1; j < pArr->cnt; j++) {
            if (pArr->pBase[i] > pArr->pBase[j]) {
                int temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[i];
                pArr->pBase[i] = temp;
            }
        }
    }
}









