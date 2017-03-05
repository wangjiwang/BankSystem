#include <iostream>
#include "Account.h"
#include "linkList.h"
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<windows.h>
#include <time.h>
using namespace std;
#define n 10
bank bank;

SLNode  *rear;
void welcome()
{


            cout<<"iriiiiiiiiiiBB       irUiirivB     Br  MorrruBi     BB  iiiiiZk "<<endl;
            cout<<"i    Mr BO      iLoBuYMB vB rM    OBioYBG   iB     Bq   iiiiiii "<<endl;
            cout<<" r   Bi BZ  ki     B  vB oB LB   iB  j BGiiiYB    I  BG       Lv"<<endl;
            cout<<" MB  Bi BN  Bv   iLBJjSM iB iB   MiMui Bk   iB      BF vrivBUikJ"<<endl;
            cout<<" Bo  B  Bu  Bi    iB  IBiVMiYB   i BviiBkuE iBN   oNBL     B    "<<endl;
            cout<<" BJ Bv  BBJFBi     M  i  iB  i   i BL  Bv B iVF  ri Bv     Bi   "<<endl;
            cout<<" BOr        Bi   rNBuiiiiFBirU     Bvi BL IBr       BY     Bi   "<<endl;
            cout<<" BBiirLvviiiBr  vBi      uB  rZ    BBr BBV  BBEi    BI  jJSBi   "<<endl;
            cout<<" Si         Y        viiiiiiivv    i   vL    iSi    Mi   iBY    "<<endl;

            cout<<"            ii              iL          q   L                   "<<endl;
            cout<<"    iii iZ  BZ        BM iFuGBi  r     MB  BB    ri      i      "<<endl;
            cout<<"    Ii  BB iB  iiBi    X kB  iBiiBY   IB  Mo IFiYBV     UBB     "<<endl;
            cout<<"    iG  Bi BiON BBi iiiL LB  iB  Bi  SjBiiiF uB Y       iBV     "<<endl;
            cout<<"      EBO kr BM      iNB vB  LB  Bi    Bi GZ UB SBi      Bi     "<<endl;
            cout<<"      iBB    BB       vB UBuLVB  Bi    Bi  ivBN  JL      B      "<<endl;
            cout<<"     iB OB  BriB      oB  Oi iB XB     r O YMi  ii       v      "<<endl;
            cout<<"    uM   MiBM  BB   vBEoq    rB       BM B  S  ovEB     MMB     "<<endl;
            cout<<"   iv    vEi    BBv vu   oNMOBMBBBBi uB  BEiiirBM Xi            "<<endl;
            cout<<"        i                                 iiriri                "<<endl;
            cout<<endl<<endl<<endl;
            system("pause");
            system("cls");
}
void cMainMenu()
{
    cout<<"1<--查询"<<"           "<<"取款-->2"<<endl;
    cout<<"3<--改密"<<"           "<<"存款-->4"<<endl;
    cout<<"5<--转账"<<"           "<<"退卡-->6"<<endl;
}

void mMainMenu()
{
    cout<<"1<--查询"<<"           "<<"取款-->2"<<endl;
    cout<<"3<--改密"<<"           "<<"存款-->4"<<endl;
    cout<<"5<--转账"<<"           "<<"重置-->6"<<endl;
    cout<<"7<--开户"<<"           "<<"销户-->8"<<endl;
    cout<<"9<--排序"<<"           "<<"退出-->10"<<endl;
}
void searchMenu()
{
    cout<<"1<--交易明细"<<"         "<<"回主菜单-->2"<<endl;
}
int main()
{
    welcome();
    int dealNum,i,j;
    SLNode *node;
    fstream file,file2,file3;
    file.open("bank.txt",ios::in);
    file2.open("history.txt",ios::in);
    file3.open("account.txt",ios::in);
    file3>>bank.account;
    for(i=1;i<=n;i++)
    {
        HeadInit(&bank.pHead[i]);
    }
    file>>bank.sum;
    for(i=1;i<=bank.sum;i++)//把交易明细文件的内容写到链表中
    {
        file2>>bank.pHead[i]->num;
        file2>>bank.pHead[i]->dealNum;

        for(j=1;j<=bank.pHead[i]->dealNum;j++){
            ListInit(&node);
            if(j==1){
                bank.pHead[i]->next=node;
            }
            else{
                rear->next=node;
            }
            file2>>node->year>>node->month>>node->day;
            file2.get();
            file2.getline(node->dealHis,20,'\n');
            rear=node;
        }
    }

    for(i=1;i<=bank.sum;i++)
    {
        file>>bank.han[i].num>>bank.han[i].pass>>bank.han[i].money>>bank.han[i].chance>>bank.han[i].name>>bank.han[i].sex>>bank.han[i].birth>>bank.han[i].id>>bank.han[i].tel;
    }
    file.close();
    file2.close();
    file.open("bank.txt",ios::out);
    file2.open("history.txt",ios::out);
    customer::login();//登入模块
    file<<bank.sum<<'\n';
    for(i=1;i<=bank.sum;i++)
    {
        file<<bank.han[i].num<<" "<<bank.han[i].pass<<" "<<bank.han[i].money<<" "<<bank.han[i].chance<<" "<<bank.han[i].name<<" "<<bank.han[i].sex<<" "<<bank.han[i].birth<<" "<<bank.han[i].id<<" "<<bank.han[i].tel<<'\n';
    }
    for(i=1;i<=bank.sum;i++)
    {
        file2<<bank.pHead[i]->num<<'\n';
        file2<<bank.pHead[i]->dealNum<<'\n';
        rear = bank.pHead[i]->next;
        for(j=1;j<=bank.pHead[i]->dealNum;j++)
        {
            file2<<rear->year<<" "<<rear->month<<" "<<rear->day<<endl;
            file2<<rear->dealHis<<'\n';
            rear=rear->next;
        }
    }
    file2.close();
    file3.close();
    file3.open("account.txt",ios::out);
    file3<<bank.account;
    file3.close();
    return 0;
}
int customer::login()//登录模块
{
    cout<<"登入模块"<<endl;
    int idType,i;
    int t,flag=0,choice;
    int flag2=0;
    char password[7];
    cout<<"请问您将以哪种身份使用本系统"<<endl;
    cout<<"1<--登录"<<"           "<<"管理-->2"<<endl;
    cin>>idType;
    system("cls");
    switch(idType)
    {
    case 1://选择使用类型为用户
            cout<<"请输入卡号:"<<endl;
            if((t=customer::searchAccount())!=0){
                    flag2 = 1;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"该卡已被冻结，请持有效证件到银行解冻！"<<endl;
                        Sleep(2000);
                        goto label;
                    }
            }
            if(flag2 == 1){
            do
            {
                cout<<"请输入密码:"<<endl;
                cin>>password;
                system("cls");
                if((strcmp(password,bank.han[t].pass))==0)
                {
                    bank.han[t].chance = 3;
                    cout<<bank.han[t].name<<",欢迎您!"<<endl;
                    flag=1;
                }
                else{
                    cout<<"密码错误，请重新输入"<<endl;
                    bank.han[t].chance--;
                    cout<<"你还有"<<bank.han[t].chance<<"次机会"<<endl;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"抱歉，您输入的密码错误次数太多！"<<endl;
                        cout<<"该卡已被冻结，请持有效证件到银行解冻！"<<endl;
                        Sleep(2000);
                        goto label;
                        break;
                    }
                }

            }while(flag==0);
            do
            {
            cMainMenu();
            cin>>choice;
            system("cls");
            if(choice<=6&&choice>0)
            {
                switch(choice){
                    case 1://跳至查询菜单;
                        bank.han[t].showRemain();
                        searchMenu();
                        cin>>choice;
                        if(choice>=1&&choice<=2)
                        {
                            switch(choice)
                            {
                            case 1:
                                bank.han[t].showHistory();//交易明细板块
                                Sleep(10000);
                                system("cls");
                                break;
                            case 2:
                                Sleep(1000);
                                system("cls");
                                break;
                            }
                        }
                        else{
                            cout<<"输入错误，将返回主菜单！"<<endl;
                            system("cls");
                        }
                        break;
                    case 2:
                        bank.han[t].outMoney();

                        break;
                    case 3:
                        bank.han[t].chPass();
                        break;
                    case 4:
                        bank.han[t].saveMoney();
                        break;
                    case 5:
                        bank.han[t].transMoney();
                        break;
                    label :case 6:
                        choice = 6;
                        break;
                }
            }
            }while(choice!=6);
            }
        break;
    case 2://选择使用类型为管理员
        manager a;
        int choice,flag=0;
        char password[7];
        do{

            mMainMenu();
            cin>>choice;
            system("cls");
            if(choice == 6)
            {
                cout<<"请输入卡号:"<<endl;
                if((t=customer::searchAccount())!=0)
                {
                    bank.han[t].forPass();
                }
                else
                    {
                        cout<<"该卡号不存在"<<endl;
                        system("cls");
                        goto label2;
                    }
            }
            if(choice<6&&choice>0)
            {
                cout<<"请输入卡号:"<<endl;
                //if((t=customer::searchAccount())!=0){
                if((t=customer::searchAccount())!=0){
                    flag2 = 1;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"该卡已被冻结，请持有效证件到银行解冻！"<<endl;
                        Sleep(2000);
                        goto label2;
                    }

                }
                else
                    {
                        cout<<"该卡号不存在"<<endl;
                        system("cls");
                        goto label2;
                    }
            }
            if(flag2 == 1){
                do
                {
                        cout<<"请输入密码:"<<endl;
                        cin>>password;
                        system("cls");
                        if((strcmp(password,bank.han[t].pass))==0)
                        {
                            bank.han[t].chance = 3;
                            cout<<bank.han[t].name<<",欢迎您!"<<endl;
                            flag = 1;
                        }
                        else{
                        cout<<"密码错误，请重新输入"<<endl;
                        bank.han[t].chance--;
                        cout<<"你还有"<<bank.han[t].chance<<"次机会"<<endl;
                        if(bank.han[t].chance==0)
                        {
                            cout<<"抱歉，您输入的密码错误次数太多！"<<endl;
                            cout<<"该卡已被冻结，请持有效证件到银行解冻！"<<endl;
                            Sleep(2000);
                            system("cls");
                            goto label2;
                            break;
                        }
                    }
                }while(flag==0);

            }

                switch(choice){
                    case 1://跳至查询菜单;
                        bank.han[t].showRemain();
                        searchMenu();
                        cin>>choice;
                        system("cls");
                        if(choice>=1&&choice<=2)
                        {
                            switch(choice)
                            {
                            case 1://交易明细板块
                                bank.han[t].showHistory();
                                Sleep(10000);
                                system("cls");
                                break;
                            case 2:
                                Sleep(1000);
                                system("cls");
                                break;
                            }
                        }
                        else{
                            cout<<"输入错误，将返回主菜单！"<<endl;
                        }
                        break;
                    case 2:
                        bank.han[t].outMoney();
                        break;
                    case 3:
                        bank.han[t].chPass();
                        break;
                    case 4:
                        bank.han[t].saveMoney();
                        break;
                    case 5:
                        bank.han[t].transMoney();
                        break;
                }
                if(choice>6&&choice<=10){
                    switch(choice){

                    case 7:
                        a.openAccount();//开户模块
                        break;
                    case 8:
                        a.delAccount();//销户模块
                        break;
                    case 9:
                        manager::sortAccount(0,bank.sum);//排序模块
                        cout<<"排序成功!"<<endl;
                        Sleep(3000);
                        system("cls");
                        break;
                    case 10:
                        break;
                    }
                }
                if(choice<=0||choice>10) {
                    cout<<"输入有误"<<endl;
                }
                label2:flag = 0;
                    flag2 = 0;
        }while(choice!=10);
        break;
    }
    return 0;
}
int customer::saveMoney()//存钱
{
    time_t timep;
    struct tm *p;
    int x,i;
    char str[10];
    cout<<"请输入您要存入的金额:"<<endl;
    cin>>x;
    time(&timep);
    p = localtime(&timep);
    sprintf(str,"%d",x);
    money = money + x;
    cout<<"您的余额为"<<money<<endl;
    for(i=1;i<=bank.sum;i++)
    {
        if(strcmp(bank.pHead[i]->num,num)==0)
        {
            SLNode *temp;
            ListInit(&temp);
            temp->year=1900+p->tm_year;
            temp->month=1+p->tm_mon;
            temp->day=p->tm_mday;
            strcpy(temp->dealHis,"存入 ");
            strcat(temp->dealHis,str);
            temp->next = bank.pHead[i]->next;
            bank.pHead[i]->next = temp;
            if(bank.pHead[i]->dealNum == 10){

            }
            if(bank.pHead[i]->dealNum <10)
            {
                bank.pHead[i]->dealNum++;
            }
            rear=bank.pHead[i]->next;
            break;
        }
    }
    Sleep(5000);
    system("cls");
    return 0;
}
int customer::saveMoney(int x)//存钱 给转账的时候用
{
    time_t timep;
    struct tm *p;
    int i;
    char str[10];
    money = money + x;
    time(&timep);
    p = localtime(&timep);
    sprintf(str,"%d",x);
    for(i=1;i<=bank.sum;i++)
    {
        if(strcmp(bank.pHead[i]->num,num)==0)
        {
            SLNode *temp;
            ListInit(&temp);
            temp->year=1900+p->tm_year;
            temp->month=1+p->tm_mon;
            temp->day=p->tm_mday;
            strcpy(temp->dealHis,"存入 ");
            strcat(temp->dealHis,str);
            temp->next = bank.pHead[i]->next;
            bank.pHead[i]->next = temp;
            if(bank.pHead[i]->dealNum == 10){

            }
            if(bank.pHead[i]->dealNum <10)
            {
                bank.pHead[i]->dealNum++;
            }
            break;
        }
    }
    Sleep(3000);
    system("cls");
    return 0;
}
int customer::outMoney()//取钱
{
    time_t timep;
    struct tm *p;
    int x,i;
    char str[10];
    int flag = 0;
    do{
        for(i=0;;i++)
        {
            cout<<"请输入您要取出的金额:"<<endl;
            cin>>x;
            sprintf(str,"%d",x);
            if(x>money){
            cout<<"余额不足，请重新输入"<<endl;
            }
            else{

                    for(i=1;i<=bank.sum;i++)
                    {
                        if(strcmp(bank.pHead[i]->num,num)==0)
                        {
                            time(&timep);
                            p = localtime(&timep);
                            SLNode *temp;
                            ListInit(&temp);
                            temp->year=1900+p->tm_year;
                            temp->month=1+p->tm_mon;
                            temp->day=p->tm_mday;
                            strcpy(temp->dealHis,"支出 -");
                            strcat(temp->dealHis,str);
                            temp->next = bank.pHead[i]->next;
                            bank.pHead[i]->next = temp;
                            if(bank.pHead[i]->dealNum == 10){

                            }
                            if(bank.pHead[i]->dealNum <10)
                            {
                                bank.pHead[i]->dealNum++;
                            }
                            money = money - x;
                            cout<<"您的余额为"<<money<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    break;
            }
        }
    }while(flag == 0);
    Sleep(3000);
    system("cls");
    return 0;
}
int customer::transMoney()//转账模块
{
    time_t timep;
    struct tm *p;
    int i,j;
    int x;
    char str[10];
    int flag = 0;
    do{
        cout<<"请输入对方卡号:"<<endl;
        if((j=customer::searchAccount())!=0){
            flag = 1;
        }
    }while(flag == 0);

    flag = 0;

    do{
        for(i=0;;i++)
        {
            cout<<"请输入您要汇款的金额:"<<endl;
            cin>>x;
            if(x>money){
                cout<<"余额不足，请重新输入"<<endl;
            }
            else{
                time(&timep);
                p = localtime(&timep);
                sprintf(str,"%d",x);
                bank.han[j].saveMoney(x);
                for(i=1;i<=bank.sum;i++)
                    {
                        if(strcmp(bank.pHead[i]->num,num)==0)
                        {
                            SLNode *temp;
                            ListInit(&temp);
                            temp->year=1900+p->tm_year;
                            temp->month=1+p->tm_mon;
                            temp->day=p->tm_mday;
                            strcpy(temp->dealHis,"支出 -");
                            strcat(temp->dealHis,str);
                            temp->next = bank.pHead[i]->next;
                            bank.pHead[i]->next = temp;
                            if(bank.pHead[i]->dealNum == 10){

                            }
                            if(bank.pHead[i]->dealNum <10)
                            {
                                bank.pHead[i]->dealNum++;
                            }
                            money = money - x;
                            flag = 1;
                            break;
                        }
                    }
                break;
            }
        }
    }while(flag == 0);

    return 0;
}
int customer::searchAccount()//查询账户
{
    int i;
    char card[20];
    cin>>card;
    for(i=1;i<n;i++)
    {
        if(strcmp(bank.han[i].num,card)==0)
        {
            break;
        }
    }
    if(i==n)
    {
        cout<<"抱歉，该账户为无效账户"<<endl;
        return 0;
    }
    else{
        return i;
    }
}
int customer::chPass()//改密码板块
{
    cout<<"请输入您的新个人密码："<<endl;
    cin>>pass;
    cout<<"更改密码成功！"<<endl;
    Sleep(1000);
    system("cls");
    return 0;

}
int customer::forPass()
{
    int flag = 0;
    char idTemp[20],telTemp[20];
    do{
        cout<<"请输入您的身份证:（输入完成后按enter确认）"<<endl;
        cin>>idTemp;
        cout<<"请输入您的预留手机号:（输入完成后按enter确认）"<<endl;
        cin>>telTemp;
        if(strcmp(id,idTemp)!=0){
            cout<<"身份证号码输入错误，请确认后重新输入："<<endl;
        }
        if(strcmp(tel,telTemp)!=0)
        {
            cout<<"预留手机号输入错误，请确认后重新输入："<<endl;
        }
        if(strcmp(id,idTemp)==0&&strcmp(tel,telTemp)==0)
        {
            flag = 1;
            cout<<"请输入您的新个人密码："<<endl;
            cin>>pass;
        }
        cout<<"更改密码成功!"<<endl;
        Sleep(3000);
        system("cls");
    }while(flag==0);
    return 0;
}
void customer::showRemain()//显示余额板块
{
    cout<<"显示余额模块"<<endl;
    cout<<"您的账户余额："<<money<<endl;
}
int manager::openAccount()//开账户板块
{
    bank.account++;
    bank.sum++;
    itoa(bank.account,bank.han[bank.sum].num,10);
    itoa(bank.account,bank.pHead[bank.sum]->num,10);
    bank.han[bank.sum].chance=3;
    cout<<"请输入您的姓名:（输入完成后按enter确认）";
    cin>>bank.han[bank.sum].name;
    cout<<"请输入您的性别：（男性为m 女性为f 输入完成后按enter确认）";
    cin>>bank.han[bank.sum].sex;
    cout<<"请输入您的出生年月日：（例1998年3月4号出生输入19980304即可，输入完成后按enter确认）";
    cin>>bank.han[bank.sum].birth;
    cout<<"请输入您的身份证号码：（输入完成后按enter确认）";
    cin>>bank.han[bank.sum].id;
    cout<<"请输入您的预留手机号：（输入完成后按enter确认）";
    cin>>bank.han[bank.sum].tel;
    cout<<"请输入您的密码：（密码为6位数字 输入完成后按enter确认）";
    cin>>bank.han[bank.sum].pass;
    bank.han[bank.sum].money=0;
    cout<<"开户成功!"<<endl;
    Sleep(3000);
    system("cls");
    return 0;
}
int manager::delAccount()//销户模块
{
    int t,flag=1,i;
    char name[20],id[20],tel[20],pass[20];
    cout<<"请输入卡号:"<<endl;
    if((t=customer::searchAccount())!=0)
    {
        do{
            switch(flag)
            {
                case 1 :
                    cout<<"请输入您的姓名:（输入完成后按enter确认）";
                    cin>>name;
                     if(strcmp(bank.han[t].name,name)!=0)
                    {
                        cout<<"该用户名不存在，请重新输入"<<endl;
                        break;
                    }
                    flag++;
                case 2 :
                    cout<<"请输入您的身份证号码：（输入完成后按enter确认）";
                    cin>>id;
                    if(strcmp(bank.han[t].id,id)!=0)
                    {
                        cout<<"您的身份证号码有误，请重新输入"<<endl;
                        break;
                    }
                    flag++;
                case 3 :
                    cout<<"请输入您的预留手机号：（输入完成后按enter确认）";
                    cin>>tel;
                    if(strcmp(bank.han[t].tel,tel)!=0)
                    {
                        cout<<"您的预留手机号有误，请重新输入"<<endl;
                        break;
                    }
                    flag++;
                case 4 :
                     cout<<"请输入您的密码：（密码为6位数字 输入完成后按enter确认）";
                     cin>>pass;
                     if(strcmp(bank.han[t].pass,pass)!=0)
                    {
                        cout<<"密码错误，请重新输入"<<endl;
                        break;
                    }
                    flag++;

            }
        }while(flag!=5);
        for(i=1;i<=bank.sum;i++)
        {
            if(strcmp(bank.pHead[i]->num,bank.han[t].num)==0)
                break;
        }
        for(;i<bank.sum;i++)
        {
            bank.pHead[i]=bank.pHead[i+1];
        }
        for(;t<bank.sum;t++)//韩剑智教我的快捷删除数组中某元素的方法
        {
            bank.han[t]=bank.han[t+1];
        }
        bank.sum--;
        for(t=1;t<=bank.sum;t++)
        {
            cout<<bank.han[t].num<<bank.han[t].name<<endl;
        }
    }
    else{
        cout<<"请确认无误后重新输入！"<<endl;
    }
    Sleep(5000);
    system("cls");
    return 0;
}
int manager::sortAccount(int left,int right)//排序模块
{
    if(left<right)//这个if循环是为了防止无限递归 用来跳出递归 因为递归的原因 使得该if有点多次使用的感觉
    {
        int i=left;
        int j=right;
        int middle;
        customer temp;
        temp=bank.han[i];
        while(i<j)//这个while保证能使一次实现基准数左边比其小 右边比其大
        {
            while(i<j && strcmp(bank.han[j].num,temp.num)>0)//从右往左找第一个比基准数 小 的数
            {
                j--;
            }
            bank.han[i]=bank.han[j];
            while(i<j &&  strcmp(bank.han[i].num,temp.num)<0)//从左往右找第一个比基准数 大 的数
            {
                i++;
            }
            bank.han[j]=bank.han[i];
            }
        middle=i;//middle = j;
        bank.han[middle]=temp;
        sortAccount(left,middle-1);//向左半部份调用
        sortAccount(middle+1,right);//向右半部份调用
    }
    return 0;

}

void customer::showHistory()//显示交易明细板块
{
    int dealNum,i,j;
    SLNode *rear;
    for(i=1;i<=bank.sum;i++)//把由交易明细文件转换而成的链表往屏幕显示
    {
        if(strcmp(bank.pHead[i]->num,num)==0){
           for(j=1;j<=bank.pHead[i]->dealNum;j++){
            if(j==1){
                cout<<bank.pHead[i]->next->year<<" "<<bank.pHead[i]->next->month<<" "<<bank.pHead[i]->next->day<<endl;
                cout<<bank.pHead[i]->next->dealHis<<endl;
                rear=bank.pHead[i]->next;
            }
            else{
                cout<<rear->next->year<<" "<<rear->next->month<<" "<<rear->next->day<<endl;
                cout<<rear->next->dealHis<<endl;
                rear=rear->next;
            }
            }
        }
    }
}
