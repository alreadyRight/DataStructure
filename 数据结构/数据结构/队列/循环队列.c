//
//  循环队列.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/22.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define array_length 8

typedef struct Queue {
    int *pBase;
    int front;
    int rear;
}DLQueue,*DLPQueue;

void init(DLPQueue);

/**
 入队
 */
bool en_queue(DLPQueue,int);//入队失败

/**
 出队
 */
bool out_queue(DLPQueue,int *);

void traverse_queue(DLPQueue);

bool full_queue(DLPQueue);

bool empty_queue(DLPQueue);

int main(void){
    
    DLQueue q;
    
    int val;
    
    init(&q);
    
    en_queue(&q, 1);
    
    en_queue(&q, 2);
    
    en_queue(&q, 3);
    
    en_queue(&q, 4);
    
    en_queue(&q, 5);
    
    en_queue(&q, 6);
    
    en_queue(&q, 7);
    
    en_queue(&q, 8);
    
    en_queue(&q, 9);
    
    traverse_queue(&q);
    
    if(out_queue(&q, &val)){
        printf("出队成功,出队的值为:%d\n",val);
    }else{
        printf("出队失败\n");
    }
    traverse_queue(&q);
    
    return 0;
}

void init(DLPQueue pQueue){
    pQueue->pBase = (int *)malloc(sizeof(int) * array_length);//代表一个数组
    pQueue->front = 0;
    pQueue->rear = 0;
}

bool full_queue(DLPQueue pQueue){
    if (pQueue->front ==  (pQueue->rear + 1) % array_length) {
        return true;
    }else{
        return false;
    }
}

bool empty_queue(DLPQueue pQueue){
    if (pQueue->front == pQueue->rear) {
        return true;
    }else{
        return false;
    }
}

bool en_queue(DLPQueue pQueue,int val){
    if (full_queue(pQueue)) {
        return false;
    }else{
        pQueue->pBase[pQueue->rear] = val;
        pQueue->rear = (pQueue->rear + 1) % array_length;
        return true;
    }
}

bool out_queue(DLPQueue pQueue,int *pVal){
    if (empty_queue(pQueue)) {
        return false;
    }else{
        *pVal = pQueue->pBase[pQueue->front];
        pQueue->front = (pQueue->front + 1) % array_length;
        return true;
    }
}

void traverse_queue(DLPQueue pQueue){
    int i = pQueue->front;
    while(i != pQueue->rear){
        printf("%d ",pQueue->pBase[i]);
        i = (i + 1) % array_length;
    }
    
}




