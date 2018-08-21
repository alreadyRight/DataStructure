//
//  typedef_02.c
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
} *PST,STU;//   ST 代表了 struct Student,    PST代表了struct Student *


int main(void){
    STU st;// struct Student st
    PST pst = &st;// struct Student *pst = &st
    pst->sid = 99;
    printf("%d",st.sid);
    
    return 0;
}
