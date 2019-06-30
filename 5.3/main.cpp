//循环链表表示队列
//将结尾节点赋给rear，以找到队尾
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#define elem int
typedef struct NODE{
    NODE * next;
    elem  e;
}NODE;
void print(NODE *pHead)
{
    NODE * p=pHead->next;
    while(p!=pHead)
    {
        printf("%d ",p->e);
        p=p->next;
    }
}
void InitQueue(NODE *&pHead,NODE *&rear)
{
    pHead = (NODE *)malloc(sizeof(NODE));
    rear = (NODE *)malloc(sizeof(NODE));
    pHead->next=pHead;
    rear=pHead;
}

void EnQ(NODE *&pHead, NODE *&rear, elem x)
{
    NODE * newnode;
    newnode=(NODE *)malloc(sizeof(NODE));  //有新节点要申请空间
    newnode->e=x;
    rear->next=newnode;
    newnode->next=pHead;
    rear=newnode;
}

void DeQ(NODE *&pHead, NODE *&rear)
{
    if(pHead->next==rear->next)
    {
        rear=pHead;

    }
    NODE *p=pHead->next->next;
    delete pHead->next;
    pHead->next=p;
}


int main()
{
    int i,en,de;
    elem m;
    NODE * pHead;
    NODE * rear;
    InitQueue(pHead,rear);
    printf("enter number and delete number\n");
    scanf("%d %d",&en,&de);
    printf("enter the elem to enter\n");
    for(i=0;i<en;i++)
    {
        scanf("%d",&m);
        EnQ(pHead,rear,m);
    }
    for(i=0;i<de;i++)
        DeQ(pHead,rear);
    print(pHead);
    return 0;
}