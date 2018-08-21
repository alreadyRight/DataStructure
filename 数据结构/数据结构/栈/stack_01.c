//
//  stack_01.c
//  栈
//
//  Created by 周冰烽 on 2018/8/20.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node *PNext;
}NODE,*PNODE;


typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;

void initStack(PSTACK);

void pushStack(PSTACK,int);

void traverseStack(PSTACK);

bool pop(PSTACK,int *);

void clearStack(PSTACK);

int main(void){

    STACK S;
    int value;
    
    initStack(&S);//造出一个空栈
    
    pushStack(&S,1);//压栈

    pushStack(&S,-2190);

    pushStack(&S,88);
    
    pushStack(&S,-4738);
    
    pushStack(&S,3289382);
    
    pushStack(&S,3232109);
    
    pushStack(&S,20);
    
    traverseStack(&S);//遍历输出
    


    clearStack(&S);
    traverseStack(&S);//遍历输出
    
    if(pop(&S,&value)){
        printf("出栈成功,出栈的元素是:%d\n",value);
    }else{
        printf("出栈失败\n");
    }//出栈
    traverseStack(&S);//遍历输出
    
    return 0;
}

void initStack(PSTACK stack){
    stack->pTop = (PNODE)malloc(sizeof(NODE));
    if (stack->pTop == NULL) {
        printf("动态内存分布失败\n");
        exit(-1);
    }
    stack->pBottom = stack->pTop;
    stack->pBottom->PNext = NULL;
}

void pushStack(PSTACK stack,int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL) {
        printf("动态内存分布失败\n");
        exit(-1);
    }
    pNew->data = val;
//    stack->pTop->PNext = pNew;
    pNew->PNext = stack->pTop;//stack->pTop 不能改成 stack->pBottom
    stack->pTop = pNew;
    return;
}

void traverseStack(PSTACK stack){
    PNODE p = stack->pTop;
    while (p != stack->pBottom) {
        printf("%d ",p->data);
        p = p->PNext;
    }
    return;
}

bool empty(PSTACK stack){
    if (stack->pTop == stack->pBottom) {
        return true;
    }else{
        return false;
    }
}

//把stack所指向的栈'出栈',并把出栈元素存入val形参所指向的变量中,如果出栈失败,返回false,否则返回true
bool pop(PSTACK stack,int *val){
    if (empty(stack)) {
//        printf("出栈失败\n");
        return false;//出栈失败
    }
    PNODE p = stack->pTop;
    *val = p->data;
    stack->pTop = p->PNext;
    free(p);
    return true;
}

//清空
void clearStack(PSTACK stack){
    if (empty(stack)) {
        return;
    }
    PNODE p = stack->pTop;
    PNODE q = NULL;
    while (p != stack->pBottom) {
        q = p->PNext;
        free(p);
        p = q;
    }
    stack->pTop = stack->pBottom;
}


