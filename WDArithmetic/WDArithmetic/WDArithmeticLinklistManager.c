//
//  WDArithmeticLinklistManager.c
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/25.
//

#include "WDArithmeticLinklistManager.h"
#include <malloc/malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int val;
    struct link *next;
}link;

link* link_init() {
    link *node = (link *)malloc(sizeof(link));
    if (node == NULL) {
        printf("空间不足");
        return node;
    }
    
    node->val = 0;
    node->next = NULL;
    
    return node;
}

link * cureatLink() {
    link *link_1 = link_init();
    link *link_2 = link_init();
    link *link_3 = link_init();
    link *link_4 = link_init();
    link *link_5 = link_init();
    link *link_6 = link_init();

    
    link *link_0 = link_init();
    
    link_0->val = 1;
    link_0->next = link_1;
    printf("%d-",link_0->val);
    
    link_1->val = 1;
    link_1->next = link_2;
    printf("%d-",link_1->val);
    
    link_2->val = 1;
    link_2->next = link_3;
    printf("%d-",link_2->val);
    
    link_3->val = 4;
    link_3->next = link_4;
    printf("%d-",link_3->val);
    
    link_4->val = 5;
    link_4->next = link_5;
    printf("%d-",link_4->val);
    
    link_5->val = 6;
    link_5->next = link_6;
    printf("%d-",link_5->val);
    
    link_6->val = 6;
    link_6->next = NULL;
    printf("%d-",link_6->val);
    
    printf("\n");
    
    return link_0;
}


//-----------------------------------------------------------------------
// 从尾部到头部打印单链表  非递归
void _sListPrintTailToHead(link *pHead) {
    
    link *cur = NULL;
    while (cur != pHead) {
        link *tail = pHead;
        while (tail->next != cur) {
            tail = tail->next;
        }
        printf("%d-",tail->val);
        cur = tail;
    }
}

//-----------------------------------------------------------------------
// 从尾部到头部打印单链表  递归
void __sListPrintTailToHead(link *pHead) {
    if (pHead == NULL) {
        return;
    }
    printf("#%d#",pHead->val);
    printf("\n");
    __sListPrintTailToHead(pHead->next);
    printf("%d-",pHead->val);
}

void sListPrintTailToHead(void) {
//    _sListPrintTailToHead(cureatLink());
    __sListPrintTailToHead(cureatLink());
}









//-----------------------------------------------------------------------
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5



link* deleteDuplication(link *n_link) {
    link *cur = n_link;
    link *prev = link_init();// 记录当前值
    link *next = link_init();// 记录下一个值
    
    while (cur != NULL) {
        if (cur->next != NULL && cur->val == cur->next->val) {// 当前是否和下一个相等
            next = cur->next;
            
            while (next->next != NULL && next != NULL && next->val == next->next->val) {// 继续监测下一节点 与 上一个节点是否相等 直到找到不相等的位置
                next = next->next;
            }
            
            if (cur == n_link) { // 如果是表头 表头直接指向 不相等的节点
                n_link = next->next;
            }else { // 如果不是表头，则当前值的下一个指向 该节点
                prev->next = next->next;
            }
            
            cur = next->next; // 原链表 指向不相等的下一个节点
            
        }else {
            prev = cur;// 如果没有相等 直接下一个走
            cur = cur->next;
        }
    }
    return n_link;
}


void deleteLinkDuplication(void) {
    
    link *link = deleteDuplication(cureatLink());
    
    while (link != NULL) {
        printf("%d-",link->val);
        link = link->next;
    }
}
