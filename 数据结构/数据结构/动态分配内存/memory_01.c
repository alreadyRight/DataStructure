//
//  memory_01.c
//  动态分配内存
//
//  Created by 周冰烽 on 2018/8/15.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
int f(void);

int main(void){
    int i = 10;
    i = f();
    printf("i = %d\n",i);
}

int f(){
    int j = 20;
    return j;
}
