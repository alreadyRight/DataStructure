//
//  汉诺塔.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>

int i = -2;

void hnt(int n, char A,char B,char C){
    i++;
    if (1 == n) {
        //直接将A柱子上的盘子从A移动到C
//        printf("将编号为%d的盘子直接从%c柱移动到%c柱",n,A,C);
        printf("第%d步:盘子编号:%d,移动:%c->%c\n",i,n,A,C);
    }else{
        //现将A柱子上的n-1个盘子 借助 C 移动到 B
        hnt(n - 1, A, C, B);
        //直接将A柱子上的盘子从A移动到C
        printf("第%d步:盘子编号:%d,移动:%c->%c\n",i,n,A,C);
        //最后将B柱子上n-1盘子借助A移动到C
        hnt(n - 1, B, A, C);
    }
}

int main(void){
    
    char ch1 = 'A';
    
    char ch2 = 'B';
    
    char ch3 = 'C';
    
    int n;
    
    printf("请输入要移动盘子的个数:");
    
    scanf("%d",&n);
    
    hnt(n,ch1,ch2,ch3);
    
    return 0;
}
