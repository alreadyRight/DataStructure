//
//  阶乘的递归实现.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

//假定n的值是1或大于1的值
long f(long n){
    if (1 == n) {
        return 1;
    }else{
        return f(n-1) * n;
    }
}

int main(void){
    
    long val;

    printf("请输入一个数字:");

    scanf("%ld",&val);

    printf("%ld\n",f(val));
    
    return 0;
}
