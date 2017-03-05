#include <stdio.h>
#include <stdlib.h>
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
typedef struct node {
  char dealHis[20];
  int year;
  int month;
  int day;       //elmΪ����������Ϣ
  struct node *next;  //nextΪָ���̽���ָ��
}SLNode;
typedef struct headNode{
    char num[20];
    int dealNum;
    SLNode *next;
}HNode;        //������������
//��������ĳ�ʼ��
void ListInit(SLNode **ppHead) {
  (*ppHead) = (SLNode*)(malloc(sizeof(SLNode)));
  (*ppHead)->next = NULL;
}
//����ͷ�ĳ�ʼ��
void HeadInit(HNode **ppHead){
  (*ppHead) = (HNode*)(malloc(sizeof(HNode)));
  (*ppHead)->next = NULL;
  (*ppHead)->dealNum = 0;
}

#endif // LINKLIST_H_INCLUDED
