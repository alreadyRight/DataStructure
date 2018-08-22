//
//  间接调用自己举例.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

void f(int n){
    j(2);
}

void j(int n){
    f(10);
}

int main(void){
    
    return 0;
}
