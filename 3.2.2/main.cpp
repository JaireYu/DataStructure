//思路
//1.L R分别是头节点和尾节点两端指向NULL
//2.L R本身不是链表主体不储存信息
#include <iostream>
#include <stdlib.h>
typedef struct DLNode{
    int e;
    DLNode * prior;
    DLNode * next;
}DLNode,*DLinkList;
void InitList(DLinkList &L)
{
    L = (DLNode *)malloc(sizeof(DLNode));
    DLinkList R = (DLNode *)malloc(sizeof(DLNode));
    L->next = R;
    R->next = NULL;
    L->prior = NULL;
    R->prior = L;
}
void ListInsert_DL(DLinkList &L,DLNode *p,DLNode *s)
{
    s->prior=p->prior;
    s->next=p;
    p->prior->next=s;
    p->prior=s;
}
void ListDelete_DL(DLinkList &L,DLNode *p,int &e)
{
    e=p->e;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
}
void ListPrint(DLinkList &L)
{
    DLinkList p;
    p=L->next;
    while(p->next!=NULL)
    {
        printf("%d ",p->e);
        p=p->next;
    }
}
int main()
{
    int x,i=0;
    char c='1';
    DLinkList L;
    InitList(L);
    while(c!='\n')
    {
        scanf("%d",&x);
        c=getchar();
        DLinkList s=(DLNode*)malloc(sizeof(DLNode));
        s->e=x;//为啥能这样写。。。
        ListInsert_DL(L,L->next,s);
        printf("The result of the %dth time insert is:",++i);
        ListPrint(L);
        printf("\n");
    }
    ListDelete_DL(L,L->next,x);
    printf("\nThe number which is deleted is %d\n",x);
    printf("The list after deleting is:");
    ListPrint(L);
    system("pause");
}