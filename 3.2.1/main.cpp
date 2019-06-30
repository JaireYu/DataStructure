#include <iostream>
#include <stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int e;
    NODE *Next;
}NODE;
void ListInsert(NODE *&pHead, int i, int x);
bool isIncrease(NODE *pHead);
void InitList(NODE *&pHead);
int main()
{
    NODE *pHead;
    int i,x;
    char c;
    InitList(pHead);
    printf("create the list space to divide and enter for end\n");
    for(i=0;;i++)
    {
        scanf("%d",&x);
        c=getchar();
        ListInsert(pHead,i,x);
        if(c=='\n')
            break;
    }
    if(isIncrease(pHead)==true)
        printf("It is increased");
    else
        printf("It is not increased");
    return 0;
}
void InitList(NODE *&pHead)
{
    pHead = (NODE *)malloc(sizeof(NODE));
    pHead->Next = NULL;
}
void ListInsert(NODE *&pHead, int i, int x)
{
    int  count=0;
    NODE *p=pHead;
    NODE * newnode;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->e=x;
    while(p!=NULL)
    {
        if(count==i)
        {
            newnode->Next=p->Next;
            p->Next=newnode;
        }
        count++;
        p=p->Next;
    }
}
bool isIncrease(NODE *pHead)
{
    if (pHead == NULL)
    {
        return false;
    }
    NODE *p = pHead->Next, *q;
    while (p->Next != NULL)
    {
        q = p;
        p = p->Next;
        if (p->e < q->e)
        {
            return false;
        }
    }
    return true;
}

