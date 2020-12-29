//
//  WDArithmeticLinklistManager.h
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/25.
//

#ifndef WDArithmeticLinklistManager_h
#define WDArithmeticLinklistManager_h

#include <stdio.h>

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
void deleteLinkDuplication(void);

// 从尾部到头部打印单链表
void sListPrintTailToHead(void);

//逆置/反转单链表
void sListReverse(void);

//合并两个有序链表,合并后依然有序
void slistMerge(void);

//查找单链表的中间节点，要求只能遍历一次链表 
void sListFindMidNode(void);

//查找单链表的倒数第k个节点，要求只能遍历一次链表
void sListFindTailKNode(void);

//删除链表的倒数第K个结点
void sListFindPop(void);

//判断是否带环  快慢指针
void sListIsCrcle(void);

#endif /* WDArithmeticLinklistManager_h */
