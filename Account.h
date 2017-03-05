#include "linkList.h"
#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
struct people
{
    char num[20];
    char pass[7];
	int money;
	char name[10];
	char sex;
	char birth[20];
	char id[20];
	char tel[20];
};
struct body
{
    char dealType[20];
    int dealMoney;
    body *next;
};
struct head
{
    int hisNumber;
    char num[20];
    body *next;
};

class person
{
public:
	char num[20];//����
	char name[10];//����
	char sex;//�Ա�
	char birth[20];//����������
	char id[20];//���֤
	char tel[20];//�绰����
	int money;//���

};
class customer : public person
{
public:
    int chance;
    char pass[7];//���� ��Ϊ000000Ϊ��Ч �������ó�char
    static int login();//��¼ģ��
	int saveMoney();//��Ǯ
	int saveMoney(int x);
	int outMoney();//ȡǮ
	int transMoney();//ת��
	int chPass();//������
    int forPass();
	void showRemain();//��ʾ���
	void showHistory();//��ѯ��ʷ���׼�¼
    static int searchAccount();//��ѯ�˻�
};
class manager : public customer
{
public:
    int openAccount();//����ģ��
    int delAccount();//����ģ��
    static int sortAccount(int left,int right);//����ģ��
};
class bank
{
public:
    customer han[10];
    HNode *pHead[10];
    int sum;//�ͻ�������
    int account ;//�ͻ��˺ų�ʼֵ
};
#endif // ACCOUNT_H_INCLUDED
