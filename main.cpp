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
    cout<<"1<--��ѯ"<<"           "<<"ȡ��-->2"<<endl;
    cout<<"3<--����"<<"           "<<"���-->4"<<endl;
    cout<<"5<--ת��"<<"           "<<"�˿�-->6"<<endl;
}

void mMainMenu()
{
    cout<<"1<--��ѯ"<<"           "<<"ȡ��-->2"<<endl;
    cout<<"3<--����"<<"           "<<"���-->4"<<endl;
    cout<<"5<--ת��"<<"           "<<"����-->6"<<endl;
    cout<<"7<--����"<<"           "<<"����-->8"<<endl;
    cout<<"9<--����"<<"           "<<"�˳�-->10"<<endl;
}
void searchMenu()
{
    cout<<"1<--������ϸ"<<"         "<<"�����˵�-->2"<<endl;
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
    for(i=1;i<=bank.sum;i++)//�ѽ�����ϸ�ļ�������д��������
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
    customer::login();//����ģ��
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
int customer::login()//��¼ģ��
{
    cout<<"����ģ��"<<endl;
    int idType,i;
    int t,flag=0,choice;
    int flag2=0;
    char password[7];
    cout<<"�����������������ʹ�ñ�ϵͳ"<<endl;
    cout<<"1<--��¼"<<"           "<<"����-->2"<<endl;
    cin>>idType;
    system("cls");
    switch(idType)
    {
    case 1://ѡ��ʹ������Ϊ�û�
            cout<<"�����뿨��:"<<endl;
            if((t=customer::searchAccount())!=0){
                    flag2 = 1;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"�ÿ��ѱ����ᣬ�����Ч֤�������нⶳ��"<<endl;
                        Sleep(2000);
                        goto label;
                    }
            }
            if(flag2 == 1){
            do
            {
                cout<<"����������:"<<endl;
                cin>>password;
                system("cls");
                if((strcmp(password,bank.han[t].pass))==0)
                {
                    bank.han[t].chance = 3;
                    cout<<bank.han[t].name<<",��ӭ��!"<<endl;
                    flag=1;
                }
                else{
                    cout<<"�����������������"<<endl;
                    bank.han[t].chance--;
                    cout<<"�㻹��"<<bank.han[t].chance<<"�λ���"<<endl;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"��Ǹ�������������������̫�࣡"<<endl;
                        cout<<"�ÿ��ѱ����ᣬ�����Ч֤�������нⶳ��"<<endl;
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
                    case 1://������ѯ�˵�;
                        bank.han[t].showRemain();
                        searchMenu();
                        cin>>choice;
                        if(choice>=1&&choice<=2)
                        {
                            switch(choice)
                            {
                            case 1:
                                bank.han[t].showHistory();//������ϸ���
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
                            cout<<"������󣬽��������˵���"<<endl;
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
    case 2://ѡ��ʹ������Ϊ����Ա
        manager a;
        int choice,flag=0;
        char password[7];
        do{

            mMainMenu();
            cin>>choice;
            system("cls");
            if(choice == 6)
            {
                cout<<"�����뿨��:"<<endl;
                if((t=customer::searchAccount())!=0)
                {
                    bank.han[t].forPass();
                }
                else
                    {
                        cout<<"�ÿ��Ų�����"<<endl;
                        system("cls");
                        goto label2;
                    }
            }
            if(choice<6&&choice>0)
            {
                cout<<"�����뿨��:"<<endl;
                //if((t=customer::searchAccount())!=0){
                if((t=customer::searchAccount())!=0){
                    flag2 = 1;
                    if(bank.han[t].chance==0)
                    {
                        cout<<"�ÿ��ѱ����ᣬ�����Ч֤�������нⶳ��"<<endl;
                        Sleep(2000);
                        goto label2;
                    }

                }
                else
                    {
                        cout<<"�ÿ��Ų�����"<<endl;
                        system("cls");
                        goto label2;
                    }
            }
            if(flag2 == 1){
                do
                {
                        cout<<"����������:"<<endl;
                        cin>>password;
                        system("cls");
                        if((strcmp(password,bank.han[t].pass))==0)
                        {
                            bank.han[t].chance = 3;
                            cout<<bank.han[t].name<<",��ӭ��!"<<endl;
                            flag = 1;
                        }
                        else{
                        cout<<"�����������������"<<endl;
                        bank.han[t].chance--;
                        cout<<"�㻹��"<<bank.han[t].chance<<"�λ���"<<endl;
                        if(bank.han[t].chance==0)
                        {
                            cout<<"��Ǹ�������������������̫�࣡"<<endl;
                            cout<<"�ÿ��ѱ����ᣬ�����Ч֤�������нⶳ��"<<endl;
                            Sleep(2000);
                            system("cls");
                            goto label2;
                            break;
                        }
                    }
                }while(flag==0);

            }

                switch(choice){
                    case 1://������ѯ�˵�;
                        bank.han[t].showRemain();
                        searchMenu();
                        cin>>choice;
                        system("cls");
                        if(choice>=1&&choice<=2)
                        {
                            switch(choice)
                            {
                            case 1://������ϸ���
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
                            cout<<"������󣬽��������˵���"<<endl;
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
                        a.openAccount();//����ģ��
                        break;
                    case 8:
                        a.delAccount();//����ģ��
                        break;
                    case 9:
                        manager::sortAccount(0,bank.sum);//����ģ��
                        cout<<"����ɹ�!"<<endl;
                        Sleep(3000);
                        system("cls");
                        break;
                    case 10:
                        break;
                    }
                }
                if(choice<=0||choice>10) {
                    cout<<"��������"<<endl;
                }
                label2:flag = 0;
                    flag2 = 0;
        }while(choice!=10);
        break;
    }
    return 0;
}
int customer::saveMoney()//��Ǯ
{
    time_t timep;
    struct tm *p;
    int x,i;
    char str[10];
    cout<<"��������Ҫ����Ľ��:"<<endl;
    cin>>x;
    time(&timep);
    p = localtime(&timep);
    sprintf(str,"%d",x);
    money = money + x;
    cout<<"�������Ϊ"<<money<<endl;
    for(i=1;i<=bank.sum;i++)
    {
        if(strcmp(bank.pHead[i]->num,num)==0)
        {
            SLNode *temp;
            ListInit(&temp);
            temp->year=1900+p->tm_year;
            temp->month=1+p->tm_mon;
            temp->day=p->tm_mday;
            strcpy(temp->dealHis,"���� ");
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
int customer::saveMoney(int x)//��Ǯ ��ת�˵�ʱ����
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
            strcpy(temp->dealHis,"���� ");
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
int customer::outMoney()//ȡǮ
{
    time_t timep;
    struct tm *p;
    int x,i;
    char str[10];
    int flag = 0;
    do{
        for(i=0;;i++)
        {
            cout<<"��������Ҫȡ���Ľ��:"<<endl;
            cin>>x;
            sprintf(str,"%d",x);
            if(x>money){
            cout<<"���㣬����������"<<endl;
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
                            strcpy(temp->dealHis,"֧�� -");
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
                            cout<<"�������Ϊ"<<money<<endl;
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
int customer::transMoney()//ת��ģ��
{
    time_t timep;
    struct tm *p;
    int i,j;
    int x;
    char str[10];
    int flag = 0;
    do{
        cout<<"������Է�����:"<<endl;
        if((j=customer::searchAccount())!=0){
            flag = 1;
        }
    }while(flag == 0);

    flag = 0;

    do{
        for(i=0;;i++)
        {
            cout<<"��������Ҫ���Ľ��:"<<endl;
            cin>>x;
            if(x>money){
                cout<<"���㣬����������"<<endl;
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
                            strcpy(temp->dealHis,"֧�� -");
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
int customer::searchAccount()//��ѯ�˻�
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
        cout<<"��Ǹ�����˻�Ϊ��Ч�˻�"<<endl;
        return 0;
    }
    else{
        return i;
    }
}
int customer::chPass()//��������
{
    cout<<"�����������¸������룺"<<endl;
    cin>>pass;
    cout<<"��������ɹ���"<<endl;
    Sleep(1000);
    system("cls");
    return 0;

}
int customer::forPass()
{
    int flag = 0;
    char idTemp[20],telTemp[20];
    do{
        cout<<"�������������֤:��������ɺ�enterȷ�ϣ�"<<endl;
        cin>>idTemp;
        cout<<"����������Ԥ���ֻ���:��������ɺ�enterȷ�ϣ�"<<endl;
        cin>>telTemp;
        if(strcmp(id,idTemp)!=0){
            cout<<"���֤�������������ȷ�Ϻ��������룺"<<endl;
        }
        if(strcmp(tel,telTemp)!=0)
        {
            cout<<"Ԥ���ֻ������������ȷ�Ϻ��������룺"<<endl;
        }
        if(strcmp(id,idTemp)==0&&strcmp(tel,telTemp)==0)
        {
            flag = 1;
            cout<<"�����������¸������룺"<<endl;
            cin>>pass;
        }
        cout<<"��������ɹ�!"<<endl;
        Sleep(3000);
        system("cls");
    }while(flag==0);
    return 0;
}
void customer::showRemain()//��ʾ�����
{
    cout<<"��ʾ���ģ��"<<endl;
    cout<<"�����˻���"<<money<<endl;
}
int manager::openAccount()//���˻����
{
    bank.account++;
    bank.sum++;
    itoa(bank.account,bank.han[bank.sum].num,10);
    itoa(bank.account,bank.pHead[bank.sum]->num,10);
    bank.han[bank.sum].chance=3;
    cout<<"��������������:��������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].name;
    cout<<"�����������Ա𣺣�����Ϊm Ů��Ϊf ������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].sex;
    cout<<"���������ĳ��������գ�����1998��3��4�ų�������19980304���ɣ�������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].birth;
    cout<<"�������������֤���룺��������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].id;
    cout<<"����������Ԥ���ֻ��ţ���������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].tel;
    cout<<"�������������룺������Ϊ6λ���� ������ɺ�enterȷ�ϣ�";
    cin>>bank.han[bank.sum].pass;
    bank.han[bank.sum].money=0;
    cout<<"�����ɹ�!"<<endl;
    Sleep(3000);
    system("cls");
    return 0;
}
int manager::delAccount()//����ģ��
{
    int t,flag=1,i;
    char name[20],id[20],tel[20],pass[20];
    cout<<"�����뿨��:"<<endl;
    if((t=customer::searchAccount())!=0)
    {
        do{
            switch(flag)
            {
                case 1 :
                    cout<<"��������������:��������ɺ�enterȷ�ϣ�";
                    cin>>name;
                     if(strcmp(bank.han[t].name,name)!=0)
                    {
                        cout<<"���û��������ڣ�����������"<<endl;
                        break;
                    }
                    flag++;
                case 2 :
                    cout<<"�������������֤���룺��������ɺ�enterȷ�ϣ�";
                    cin>>id;
                    if(strcmp(bank.han[t].id,id)!=0)
                    {
                        cout<<"�������֤������������������"<<endl;
                        break;
                    }
                    flag++;
                case 3 :
                    cout<<"����������Ԥ���ֻ��ţ���������ɺ�enterȷ�ϣ�";
                    cin>>tel;
                    if(strcmp(bank.han[t].tel,tel)!=0)
                    {
                        cout<<"����Ԥ���ֻ�����������������"<<endl;
                        break;
                    }
                    flag++;
                case 4 :
                     cout<<"�������������룺������Ϊ6λ���� ������ɺ�enterȷ�ϣ�";
                     cin>>pass;
                     if(strcmp(bank.han[t].pass,pass)!=0)
                    {
                        cout<<"�����������������"<<endl;
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
        for(;t<bank.sum;t++)//�����ǽ��ҵĿ��ɾ��������ĳԪ�صķ���
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
        cout<<"��ȷ��������������룡"<<endl;
    }
    Sleep(5000);
    system("cls");
    return 0;
}
int manager::sortAccount(int left,int right)//����ģ��
{
    if(left<right)//���ifѭ����Ϊ�˷�ֹ���޵ݹ� ���������ݹ� ��Ϊ�ݹ��ԭ�� ʹ�ø�if�е���ʹ�õĸо�
    {
        int i=left;
        int j=right;
        int middle;
        customer temp;
        temp=bank.han[i];
        while(i<j)//���while��֤��ʹһ��ʵ�ֻ�׼����߱���С �ұ߱����
        {
            while(i<j && strcmp(bank.han[j].num,temp.num)>0)//���������ҵ�һ���Ȼ�׼�� С ����
            {
                j--;
            }
            bank.han[i]=bank.han[j];
            while(i<j &&  strcmp(bank.han[i].num,temp.num)<0)//���������ҵ�һ���Ȼ�׼�� �� ����
            {
                i++;
            }
            bank.han[j]=bank.han[i];
            }
        middle=i;//middle = j;
        bank.han[middle]=temp;
        sortAccount(left,middle-1);//����벿�ݵ���
        sortAccount(middle+1,right);//���Ұ벿�ݵ���
    }
    return 0;

}

void customer::showHistory()//��ʾ������ϸ���
{
    int dealNum,i,j;
    SLNode *rear;
    for(i=1;i<=bank.sum;i++)//���ɽ�����ϸ�ļ�ת�����ɵ���������Ļ��ʾ
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
