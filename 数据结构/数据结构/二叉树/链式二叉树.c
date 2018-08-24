//
//  链式二叉树.c
//  数据结构
//
//  Created by 周冰烽 on 2018/8/24.
//  Copyright © 2018年 周冰烽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct BTNode {
    char data;
    struct BTNode *pLChild;//p 代表指针 ,L 代表左, child 代表子树
    struct BTNode *pRChild;
};

struct BTNode * CreateBTree(void);

void PreTraverseBTree(struct BTNode *);

void InTraverseBTree(struct BTNode *);

void PostTraverseBTree(struct BTNode *);



int main(void){
    
    struct BTNode *pt = CreateBTree();
    printf("先序遍历-------------开始\n");
    PreTraverseBTree(pt);//先序
    printf("先序遍历-------------结束\n");
    
    printf("中序遍历-------------开始\n");
    InTraverseBTree(pt);//中序
    printf("中序遍历-------------结束\n");
    
    printf("后序遍历-------------开始\n");
    PostTraverseBTree(pt);//后序
    printf("后序遍历-------------结束\n");
    
    return 0;
}


struct BTNode * CreateBTree(void){
    struct BTNode *pA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pE = (struct BTNode *)malloc(sizeof(struct BTNode));
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    
    pA->pLChild = pB;
    pA->pRChild = pC;
    
    pB->pLChild = pB->pRChild = NULL;
    
    pC->pLChild = pD;
    pC->pRChild = NULL;
    
    pD->pLChild = NULL;
    pD->pRChild = pE;
    
    pE->pLChild = pE->pRChild = NULL;
    
    return pA;
}

void PreTraverseBTree(struct BTNode *pT){
    /*
        伪算法
        //先访问根节点
        //再先序访问左子树
        //再先序访问右子树
     */
    if (NULL != pT) {
        printf("%c\n",pT->data);
        //pT->pLChild 可以代表整个左子树
        if (NULL != pT->pLChild) {
            PreTraverseBTree(pT->pLChild);
        }
        if (NULL != pT->pRChild) {
            PreTraverseBTree(pT->pRChild);
        }
    }
}

void InTraverseBTree(struct BTNode *pT){
    /*
        伪算法
        中序遍历左子树
        访问根节点
        中序遍历右子树
     */
    if (NULL != pT) {
        if (NULL != pT->pLChild) {
            InTraverseBTree(pT->pLChild);
        }
        printf("%c\n",pT->data);
        if (NULL != pT->pRChild) {
            InTraverseBTree(pT->pRChild);
        }
    }
}

void PostTraverseBTree(struct BTNode *pT){
    /*
        伪算法
        后序遍历左子树
        后序遍历右子树
        访问根节点
     */
    if (NULL != pT) {
        if (NULL != pT->pLChild) {
            PostTraverseBTree(pT->pLChild);
        }
        if (NULL != pT->pRChild) {
            PostTraverseBTree(pT->pRChild);
        }
        printf("%c\n",pT->data);
    }
}
