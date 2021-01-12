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

// 求环列表的长度
void sListCycleLen(void);

//求环的入口点（环的入口点就是一个从链表开始另一个从相遇点开，当他们相交的点就是入口点）
void sListCrossEntreNode (void);

//判断两个链表是否相交。（假设链表不带环）
void sListIsCrossNode(void);

#endif /* WDArithmeticLinklistManager_h */
