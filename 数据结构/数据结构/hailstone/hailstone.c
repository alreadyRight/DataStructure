//
//  hailstone.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/27.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

int hailstone(int num){
    int len = 1;
    while (1 < num) {
        printf("%d \n",num);
        len++;
        if (num % 2 == 0) {
            num = num / 2;
        }else{
            num = num * 3 + 1;
        }
    }
    printf("%d \n",num);
    return len;
}


int main(void){
    
    printf("haistone's length is %d \n",hailstone(27));
    
    return 0;
}
