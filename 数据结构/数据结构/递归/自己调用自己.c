//
//  自己调用自己.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

void f(int n){
    if (n == 1) {
        printf("666\n");
    }else{
        printf("555\n");
        f(n-1);
    }
}

int main(void){
    f(6);
    return 0;
}
