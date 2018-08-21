//
//  malloc_01.c
//  动态分配内存
//
//  Created by 周冰烽 on 2018/8/15.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main (void){
    
//    int a[5] = {1,2,3,4,5};
    
    int len;
    
    printf("请输入数组的长度:\n");
    scanf("%d",&len);
    int *pArr = (int *)malloc(sizeof(int) * len);//(int *) 强制类型转换,告诉编译器,第一个字节地址表示的是整型类型的地址
    *pArr = 4;//类似于 a[0] = 4;
    pArr[1] = 20;//类似于a[1] = 20;
    
//    printf("%d,%d\n",*pArr,pArr[1]);
    
    for (int i = 0; i < len; i++) {
        printf("请输入第%d个元素:",i);
        scanf("%d",&pArr[i]);
    }
    
    for (int i = 0; i < len; i++) {
        printf("%d\n",*(pArr + i));
    }
    
    free(pArr);//把pArr所代表的动态分配的20个字节内存释放
    
    printf("%d,%d\n",*pArr,pArr[1]);
    
    return 0;
}
