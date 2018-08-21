//
//  typedef_01.c
//  数组
//
//  Created by 周冰烽 on 2018/8/17.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

typedef int dlInt;//为int再多取一个名字,dlInt等价于int

typedef struct Student {
    int sid;
    char name[2000];
    char sex;
} *PST;//PST 等价于 typedef struct Student *


int main(void){
//
//    dlInt i = 30;
//
//    printf("%d",i);
    
    struct Student st;
    
    PST p = &st;
    
    p->sid = 99;
    
    printf("%d\n",st.sid);
    
    return 0;
}
