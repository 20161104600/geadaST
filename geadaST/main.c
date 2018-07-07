//
//  main.c
//  geadaST
//
//  Created by Hxxguohua on 2018/7/3.
//  Copyright © 2018年 Hxxguohua. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>
#define MAXSIZE 30
struct Student
{
    char name[10];
    char sex[3];
    char proname[10];
    char protype[10];
    int num;
    char class[10];
    int Score;
};
typedef struct Student ElemTypeS;

typedef struct
{
    ElemTypeS elem[MAXSIZE];
    int lastS;
}SeqListS;

struct Teacher
{
    char name[10];
    char sex[3];
    int num;
    int Score;
};
typedef struct Teacher ElemTypeT;

typedef struct
{
    ElemTypeT elem[MAXSIZE];
    int lastT;
}SeqListT;

void saveS(SeqListS *L)   //存储学生数据
{
    int n,i=0;
    FILE *fp;
    printf("是否需要保存文件：1.是   2.否\n");
    scanf("%d",&n);
    if(n)
    {
        if (L->lastS==-1)
            printf("无记录，无法保存！");
        else
            if((fp=fopen("/Users/hxxguohua/Desktop/grade/geadaST/geadaST/student.csv","w"))==NULL)  //打开文件并判断打开是否正常
            {
                printf("不能打开文件！\n");   //打开文件错误
            }
            else if(L->lastS!=-1)
            {
                for (i=0;i<=L->lastS;i++)
                {
                    //fprintf(fp,"|%-8d|%-8s|%-10d|%-8d|%-8d|%-8d|%-8d|\n",i+1,L->elem[i].name,L->elem[i].num,L->elem[i].MathScore,L->elem[i].ChinaseScore,L->elem[i].EnglishScore,L->elem[i].Score);
                    fprintf(fp,"%d,%s,%s,%s,%s,%d,%s\n",i+1,L->elem[i].name,L->elem[i].sex,L->elem[i].proname,L->elem[i].protype,L->elem[i].num,L->elem[i].class);
                }
                printf("文件保存成功！\n");
                fclose(fp);
            }
    }
    else
    {
        return;
    }
}

void saveT(SeqListT *L)   //存储老师数据
{
    int n,i=0;
    FILE *fp;
    printf("是否需要保存文件：1.是   2.否\n");
    scanf("%d",&n);
    if(n)
    {
        if (L->lastT==-1)
            printf("无记录，无法保存！");
        else
            if((fp=fopen("/Users/hxxguohua/Desktop/grade/geadaST/geadaST/teacher.csv","w"))==NULL)  //打开文件并判断打开是否正常
            {
                printf("不能打开文件！\n");   //打开文件错误
            }
            else if(L->lastT!=-1)
            {
                for (i=0;i<=L->lastT;i++)
                {
                    //fprintf(fp,"|%-8d|%-8s|%-10d|%-8d|%-8d|%-8d|%-8d|\n",i+1,L->elem[i].name,L->elem[i].num,L->elem[i].MathScore,L->elem[i].ChinaseScore,L->elem[i].EnglishScore,L->elem[i].Score);
                    fprintf(fp,"%d,%s,%s,%d\n",i+1,L->elem[i].name,L->elem[i].sex,L->elem[i].num);
                }
                printf("文件保存成功！\n");
                fclose(fp);
            }
    }
    else
    {
        return;
    }
}

char menu()
{
    int input;
    printf("\n");
    printf("         |************评分系统*************|        \n");
    printf("         |一============================一|        \n");
    printf("         |            菜单选项             |        \n");
    printf("         |-------------------------------|        \n");
    printf("         |    1---输入                    |        \n");
    printf("         |    2---增加                    |        \n");
    printf("         |    3---删除                    |        \n");
    printf("         |    4---修改                    |        \n");
    printf("         |    5---查找                    |        \n");
    printf("         |    6---评分                    |        \n");
    printf("         |    7---在文件中读取              |        \n");
    printf("         |    8---保存到文件中              |        \n");
    printf("         |    9---退出                    |        \n");
    
    do
    {
        printf("\n选择你要进行的操作(1-9):");
        scanf("%d",&input);
    }
    while(input<1 || input>9);
    return input;
}

bool InsertT(SeqListT* L) //增加老师
{
    int Int;
    printf("请输入要插入老师的相关信息：");
    ElemTypeT X;
    printf("请输入老师姓名：\n");
    scanf("%s",X.name);
    printf("请输入老师性别：\n");
    scanf("%s",X.sex);
    printf("输入老师的联系方式：\n");
    scanf("%d",&X.num);
    printf("请输入要插入的位置:\n");
    scanf("%d",&Int);
    int j;
    if(L->lastT==MAXSIZE-1){
        printf("线性表满！\n");
        return false;
    }
    if(Int<1 || Int>L->lastT+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=L->lastT; j>=Int-1; j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[Int-1]=X;
    L->lastT++;
    return true;
}

bool InsertS(SeqListS* L) //增加学生
{
    int Int;
    printf("请输入要插入学生的相关信息：");
    ElemTypeS X;
    printf("请输入学生姓名：\n");
    scanf("%s",X.name);
    printf("请输入学生性别：\n");
    scanf("%s",X.sex);
    printf("输入学生的班级：\n");
    scanf("%s",X.class);
    printf("输入学生的联系方式：\n");
    scanf("%d",&X.num);
    printf("输入学生的节目名称：\n");
    scanf("%s",X.proname);
    printf("输入学生的节目类型：\n");
    scanf("%s",X.protype);
    printf("请输入要插入的位置:\n");
    scanf("%d",&Int);
    int j;
    if(L->lastS==MAXSIZE-1){
        printf("线性表满！\n");
        return false;
    }
    if(Int<1 || Int>L->lastS+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=L->lastS; j>=Int-1; j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[Int-1]=X;
    L->lastS++;
    return true;
}

bool deletT(SeqListT* L) //删除老师信息
{
    int i,j;
    printf("请选择要删除老师信息的位置:\n");
    scanf("%d/n",&i);
    if(L->lastT==-1){
        printf("没有可以删除的老师信息！\n");
        return false;
    }
    if(i<1 || i>L->lastT+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=i-1; j<L->lastT; j++)
    {
        L->elem[j]=L->elem[j+1];
    }
    L->lastT--;
    printf("删除成功！\n");
    return true;
}

bool deletS(SeqListS* L) //删除学生信息
{
    int i,j;
    printf("请选择要删除学生信息的位置:\n");
    scanf("%d/n",&i);
    if(L->lastS==-1){
        printf("没有可以删除的学生信息！\n");
        return false;
    }
    if(i<1 || i>L->lastS+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=i-1; j<L->lastS; j++)
    {
        L->elem[j]=L->elem[j+1];
    }
    L->lastS--;
    printf("删除成功！\n");
    return true;
}

void chenageS(SeqListS* L) //修改学生信息
{
    int i,j,D=1;
    printf("请输入要修改学生的序号:");
    scanf("%d",&i);
    while(D==1)
    {
        printf("-----请输入要修改什么学生信息：------\n");
        printf("-----     1.   姓名        ------\n");
        printf("-----     2.   性别        ------\n");
        printf("-----     3.   节目名称     ------\n");
        printf("-----     4.   节目类型     ------\n");
        printf("-----     5.   联系方式     ------\n");
        scanf("%d",&j);
        switch(j)
        {
            case 1:
                printf("修改姓名为：\n");
                scanf("%s",L->elem[i-1].name);
                break;
            case 2:
                printf("修改性别为：\n");
                scanf("%s",L->elem[i-1].sex);
                break;
            case 3:
                printf("修改节目名称为：\n");
                scanf("%s",L->elem[i-1].proname);
                break;
            case 4:
                printf("修改节目类型为：\n");
                scanf("%s",L->elem[i-1].protype);
                break;
            case 5:
                printf("修改联系方式为：\n");
                scanf("%d",&L->elem[i-1].num);
                break;
        }
        printf("是否继续修改学生们的信息：1.是   2.否\n");
        scanf("%d",&D);
    }
}

void chenageT(SeqListT* L) //修改老师信息
{
    int i,j,D=1;
    printf("请输入要修改老师的序号:");
    scanf("%d",&i);
    while(D==1)
    {
        printf("-----请输入要修改什么老师信息：------\n");
        printf("-----     1.   姓名        ------\n");
        printf("-----     2.   性别        ------\n");
        printf("-----     3.   联系方式     ------\n");
        scanf("%d",&j);
        switch(j)
        {
            case 1:
                printf("修改姓名为：\n");
                scanf("%s",L->elem[i-1].name);
                break;
            case 2:
                printf("修改性别为：\n");
                scanf("%s",L->elem[i-1].sex);
                break;
            case 3:
                printf("修改联系方式为：\n");
                scanf("%d",&L->elem[i-1].num);
                break;
        }
        printf("是否继续修改学生们的信息：1.是   2.否\n");
        scanf("%d",&D);
    }
}

void sortMax(SeqListT *L)
{
    int i,j;
    ElemTypeT X;
    for(j=0;j<L->lastT-1;j++)
    {
        for(i=0;i<=L->lastT-1-j;i++)
        {
            if(L->elem[i].Score<L->elem[i+1].Score)
            {
                X=L->elem[i];
                L->elem[i]=L->elem[i+1];
                L->elem[i+1]=X;
            }
        }
    }
}

int count(SeqListT L)
{
    int i,j=0,c=0;
    int average;
    for(i=1;i<=L.lastT-1;i++)
    {
        j=j+L.elem[i].Score;
        c++;
    }
    average=j/c;
    return average;
}
void readinT(SeqListT *L)// 输入老师相关信息
{
    int r;
    int i;
    printf("输入想要录入教师的数量:");
    scanf("%d",&r);
    //char name1[10];
    for(i=0; i<=r-1; i++)
    {
        //ElemType X;
        //scanf("%d",&X.num);
        //scanf("%d",&X.score);
        //L->elem[i]=X;
        /*
         char name[10];
         int num;
         int MathScore;
         int ChinaseScore;
         int EnglishScore;
         */
        L->lastT++;
        printf("----------------------------\n");
        printf("请输入第%d名老师的信息：\n",i+1);
        printf("请输入老师的姓名\n");
        scanf("%s",L->elem[i].name);
        //strcpy(L->elem[i].name,name1);
        printf("请输入老师的性别：\n");
        scanf("%s",L->elem[i].sex);
        printf("请输入老师的联系方式：\n");
        scanf("%d",&L->elem[i].num);
    }
}

void readinS(SeqListS *L)// 输入学生相关信息
{
    int r;
    int i;
    printf("输入想要录入学生的数量:");
    scanf("%d",&r);
    //char name1[10];
    for(i=0; i<=r-1; i++)
    {
        L->lastS++;
        printf("----------------------------\n");
        printf("请输入第%d名学生的信息：\n",i+1);
        printf("请输入学生的姓名\n");
        scanf("%s",L->elem[i].name);
        //strcpy(L->elem[i].name,name1);
        printf("请输入学生的性别：\n");
        scanf("%s",L->elem[i].sex);
        printf("请输入学生的节目名称：\n");
        scanf("%s",L->elem[i].proname);
        printf("请输入学生的节目类型：\n");
        scanf("%s",L->elem[i].protype);
        L->elem[i].Score=0;
        printf("请输入学生的联系方式：\n");
        scanf("%d",&L->elem[i].num);
        printf("请输入学生的班级：\n");
        scanf("%s",L->elem[i].class);
    }
}


bool   findNameT(SeqListT L) //按姓名查找老师int
{
    char name2[10];//
    printf("要查找的老师姓名为:\n");
    scanf("%s",name2);
    int i=0;
    while ((i<=L.lastT)&&(strcmp(L.elem[i].name,name2)))//查找该老师
        i++;
    if  (i<=L.lastT)
    {
        printf("|  序号   |   姓名   |   性别  |   联系方式  |\n");
        printf("|--------|----------|--------|----———----|\n");
        printf("|%-8d|%-8s|%-10s|%-10d|\n",i+1,L.elem[i].name,L.elem[i].sex,L.elem[i].num);
        return true;
    }
    else
        printf("没有找到这名教师！");  //没找到返回空序号
    return false;
}

bool  findNameS(SeqListS L) //查找学生int
{
    char name2[10];
    printf("要查找的学生姓名为:\n");
    scanf("%s",name2);
    int i=0;        //  顺序扫描表直到找到，或找不到 到表尾
    while ((i<=L.lastS)&&(strcmp(L.elem[i].name,name2)))//找到后印相关信息
        i++;
    if  (i<=L.lastS)
    {
        printf("|   序号  |    姓名   |  性别  |   节目名称  |  节目类型  |   联系方式  |  班级   |\n");
        printf("|--------|----------|--------|----———----|----———----|----———----|--------|\n");
        printf("|   %d   |    %s    |   %s   |  %s       |  %s       | %d        |   %s   |\n",i+1,L.elem[i].name,L.elem[i].sex,L.elem[i].proname,L.elem[i].protype,L.elem[i].num,L.elem[i].class);
        return true;
    }
    else
        printf("没有找到这名学生！\n");  //没找到返回空序号
    return false;
}

void find(SeqListT L1,SeqListS L2)
{
    int a;
    if(L1.lastT==-1 && L2.lastS==-1)
        printf("没有可以查询的信息!\n");
    else
    {
        printf("查找学生还是教师（1.教师 2.学生）\n");
        scanf("%d",&a);
        if(a==1)
        {
            findNameT(L1);
        }
        else if(a==2)
        {
            findNameS(L2);
        }
        else if(a!=1&&a!=2)
        {
            printf("输入信息有问题！\n");
        }
    }
}

void grade(SeqListT *L1,SeqListS *L2)//评分
{
    int s=0,t=0,i,j=1,a;
    a=L1->lastT;
    printf("开始评分\n");
    for(s=0;s<=L2->lastS;s++)
    {
        printf("----------------------------\n");
        printf("对第%d名同学评分：\n",s+1);
        for(t=0;t<=L1->lastT;t++)
        {
            printf("请输入%s老师给予的分数：",L1->elem[t].name);
            scanf("%d",&L1->elem[t].Score);
            printf("\n");
        }
        printf("已经对第%d名同学完成评分，是否保存（保存后不可更改）！（1.保存   2.修改信息）：\n",s+1);
        scanf("%d",&j);
        while(j==2)
        {
            //readin(&L1);
            printf("请输入要修改第几名教师所给的分数：\n");
            scanf("%d",&i);
            printf("请输入分数：\n");
            scanf("%d",&L1->elem[i-1].Score);
            printf("是否继续修改其他老师给的分数：1.是   2.否\n");
            scanf("%d",&j);
        }
        count(*L1);
        printf("去除一个最高分：%d\n",L1->elem[0].Score);
        printf("去除一个最低分：%d\n",L1->elem[a].Score);
        printf("最后%s同学得分为：%d\n\n1",L2->elem[s].name,count(*L1));
    }
}

int  main()
{
    SeqListS l1;
    SeqListT l2;
    l1.lastS=-1;
    l2.lastT=-1;
    while(1)
    {
        switch(menu())
        {
            case 1:
                readinS(&l1);//输入
                //display(l2);
                break;
            case 2:
                Insert(&l2);//增加
                break;
            case 3:
                delet(&l2);//删除
                //display(l);
                break;
            case 4:
                chenage(&l1);//修改
                //display(l);
                break;
            case 5:
                find(l2,l1);//查找
                break;
            case 6:
                grade(&l2, &l1);//评分
                //display(l);
                break;
            case 7:
                 //load(&l1);//读取
                 break;
            case 8:
                 saveS(&l1);//保存
                 break;
            case 9:
                printf("-----–谢谢使用-----\n");
                exit(1);
        }
    }
}
