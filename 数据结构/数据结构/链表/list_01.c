//
//  list_01.c
//  链表_02
//
//  Created by 周冰烽 on 2018/8/20.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node *PNext;
} Node,*PNode;

/**
 创建链表
 */
PNode create_list(void);

/**
 链表列表
 */
void traverse_list(PNode);

/**
 链表长度
 */
int length_list(PNode);

/**
 链表排序
 */
void sort_list(PNode);

/**
 判断链表是否为空
 */
bool is_empty(PNode);

/**
 插入
 */
bool insert_list(PNode,int,int);

/**
 删除
 */
bool delete_list(PNode,int,int *);

int main (void){
    //创建链表
    PNode PHead = create_list();
    traverse_list(PHead);
    
    printf("链表的长度是:%d\n",length_list(PHead));
    
    sort_list(PHead);
    traverse_list(PHead);
    
    if (is_empty(PHead)) {
        printf("链表为空\n");
    }else{
        printf("链表不为空\n");
    }
    
    if (insert_list(PHead, -10, 108)) {
        traverse_list(PHead);
    }
    
    int val;
    if (delete_list(PHead, 3, &val)) {
        printf("删除元素的值为:%d\n",val);
        traverse_list(PHead);
    }
    
    return 0;
}

PNode create_list(void){
    //创建头结点
    PNode PHead = (PNode)malloc(sizeof(Node));
    PNode PTail = PHead;
    PTail->PNext = NULL;
    printf("请输入链表长度:");
    int len;
    int data;
    scanf("%d",&len);
    for (int i = 0; i < len; i++) {
        printf("请输入第%d个节点的数据,data:",i + 1);
        scanf("%d",&data);
        PNode PNew = (PNode)malloc(sizeof(Node));
        PNew->data = data;
        PTail->PNext = PNew;
        PTail = PNew;
        PTail->PNext = NULL;
    }
    return PHead;
}

void traverse_list(PNode PHead){
    int i = 0;
    PNode node = PHead->PNext;
    while (node != NULL) {
        printf("第%d个元素是:%d,\n",i+1,node->data);
        node = node->PNext;
        ++i;
    }
    return;
}

int length_list(PNode PHead){
    int len = 0;
    PNode node = PHead->PNext;
    while (node != NULL) {
        node = node->PNext;
        ++len;
    }
    return len;
}

void sort_list(PNode PHead){
    int tempData,i,j;
    PNode p1,p2;
    int len = length_list(PHead);
    for (p1 = PHead->PNext,i = 0; i < len; ++i,p1 = p1->PNext) {
        for (j = i + 1,p2 = p1->PNext; j < len; ++j,p2 = p2->PNext) {
            if (p1->data > p2->data) {
                tempData = p1->data;
                p1->data = p2->data;
                p2->data = tempData;
            }
        }
    }
}

bool is_empty(PNode PHead){
    if (PHead->PNext == NULL) {
        return true;
    }
    return false;
}

//在PHead所指向的链表的第pos个节点的前面插入一个新的节点,该节点的值是val,并且pos的值从1开始
bool insert_list(PNode PHead,int pos,int val){
    
    //求出pos-1的节点
    PNode node = PHead;
    int i = 0;
    while (node != NULL && i < pos - 1) {
        node = node->PNext;
        ++i;
    }
    
//    if (pos > length_list(PHead) || pos < 1) {
//        printf("插入失败");
//        return false;
//    }
    
    if (node == NULL || i > pos-1) {
        printf("插入失败\n");
        return false;
    }
    
    PNode pNew = (PNode)malloc(sizeof(Node));
    if (pNew == NULL) {
        printf("动态创建内存失败");
        exit(-1);
    }
    pNew->data = val;
    PNode pOld = node->PNext;
    node->PNext = pNew;
    pNew->PNext = pOld;
    
    return true;
}

bool delete_list(PNode pHead,int pos,int *val){
    PNode p = pHead;
    int i;
    for (i = 0; i < pos - 1; i++) {
        if (p == NULL) {
            break;
        }
        p = p->PNext;
    }
    if (p == NULL || i > pos-1) {
        printf("删除失败\n");
        return false;
    }
    PNode p2 = p->PNext;
    PNode p3 = p2->PNext;
    p->PNext = p3;
    *val = p2->data;
    free(p2);
    return true;
}




