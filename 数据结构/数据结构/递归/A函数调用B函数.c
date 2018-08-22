//
//  A函数调用B函数.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

int f(int n){
    n += 2;
    return n;
}




int main(void){
    
    int val = 5;
    
    val = f(val);
    
    printf("%d\n",val);
    
    return 0;
}
