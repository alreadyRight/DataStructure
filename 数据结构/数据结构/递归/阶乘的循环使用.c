//
//  阶乘的循环使用.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>



int main(void){
    
    int val;
    int mult = 1;
    
    printf("请输入一个数字:");
    
    scanf("%d",&val);
    
    for (int i = 1; i <= val; i++) {
        mult = mult * i;
    }
    
    printf("%d\n",mult);
    
    return 0;
}
