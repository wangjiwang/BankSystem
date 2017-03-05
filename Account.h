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
	char num[20];//卡号
	char name[10];//名字
	char sex;//性别
	char birth[20];//出生年月日
	char id[20];//身份证
	char tel[20];//电话号码
	int money;//存款

};
class customer : public person
{
public:
    int chance;
    char pass[7];//密码 因为000000为无效 所以设置成char
    static int login();//登录模块
	int saveMoney();//存钱
	int saveMoney(int x);
	int outMoney();//取钱
	int transMoney();//转账
	int chPass();//改密码
    int forPass();
	void showRemain();//显示余额
	void showHistory();//查询历史交易记录
    static int searchAccount();//查询账户
};
class manager : public customer
{
public:
    int openAccount();//开户模块
    int delAccount();//销户模块
    static int sortAccount(int left,int right);//排序模块
};
class bank
{
public:
    customer han[10];
    HNode *pHead[10];
    int sum;//客户总人数
    int account ;//客户账号初始值
};
#endif // ACCOUNT_H_INCLUDED
