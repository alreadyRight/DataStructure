//
//  1+2+100的和.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

int sum(int n){
    if (1 == n) {
        return 1;
    }else{
        return (sum(n-1) + n);
    }
}

int main(void){
    printf("%d\n",sum(100));
    
    return 0;
}
