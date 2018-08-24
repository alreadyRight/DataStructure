//
//  快速排序.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/24.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

/**
 快速排序

 @param a 数组
 @param l 要排序的第一个元素的下标
 @param h 要排序的最后一个元素的下标
 */
void QuickSort(int *a,int l,int h);


/**
 找到第l个元素在数组中的具体位置

 @param a 数组
 @param l 要找的位置区间的第一个元素的下标
 @param h 要找的位置区间的最后一个元素的下标
 @return 具体位置(下标)
 */
int FindPos(int *a,int l,int h);


int main(void){
    int a[8] = {1,4,6,5,-29,87,9,-10};
    
    QuickSort(a,0,7);//第一个参数
    
    for (int i = 0; i < 8; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}

void QuickSort(int *a,int low,int high){
    int pos;
    if (low < high) {
        pos = FindPos(a,low,high);
        QuickSort(a,low,pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

int FindPos(int *a,int low,int high){
    int val = a[low];
    while (low < high) {
        while (low < high && a[high]>=val) {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= val) {
            ++low;
        }
        a[high] = a[low];
    }//终止循环之后low和high一定是相等的
    a[low] = val;
    return low;
}






