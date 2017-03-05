#include <stdio.h>
#include <stdlib.h>
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
typedef struct node {
  char dealHis[20];
  int year;
  int month;
  int day;       //elm为结点的数据信息
  struct node *next;  //next为指向后继结点的指针
}SLNode;
typedef struct headNode{
    char num[20];
    int dealNum;
    SLNode *next;
}HNode;        //单链表结点类型
//链表身体的初始化
void ListInit(SLNode **ppHead) {
  (*ppHead) = (SLNode*)(malloc(sizeof(SLNode)));
  (*ppHead)->next = NULL;
}
//链表头的初始化
void HeadInit(HNode **ppHead){
  (*ppHead) = (HNode*)(malloc(sizeof(HNode)));
  (*ppHead)->next = NULL;
  (*ppHead)->dealNum = 0;
}

#endif // LINKLIST_H_INCLUDED
