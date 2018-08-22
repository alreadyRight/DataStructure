//
//  不同函数之间的相互调用.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

void f(void);
void g(void);
void k(void);

int main(void){
    f();
    
    return 0;
}

void f(){
    printf("%s\n",__func__);
    g();
}

void g(){
    printf("%s\n",__func__);
    k();
}

void k(){
    printf("%s\n",__func__);
//    f();
}
