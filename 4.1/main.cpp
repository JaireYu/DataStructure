#include <iostream>
#define Maxsize 100
#define elem int
typedef struct{
    elem q[Maxsize];
    int front,rear;
}Queue;
void InitQ(Queue &q);
bool EnQ(Queue &q,elem x);
bool DeQ(Queue &q,elem &e);
int QueueLength(Queue q);
void Copy(Queue &q1,Queue &q2);
void Print(Queue q);
int main()
{
    Queue q1,q2;
    InitQ(q1);
    InitQ(q2);
    elem x;char c='1';
    printf("create a list space to divide, enter to stop");
    while(c!='\n')
    {
        scanf("%d", &x);
        c = getchar();
        EnQ(q1, x);
    }
    Copy(q1,q2);
    Print(q2);
    return 0;
}
void InitQ(Queue &q)
{
    q.rear=q.front=0;
}
bool EnQ(Queue &q,elem x)
{
    if((q.rear+1)%Maxsize==q.front)
        return false;
    q.q[q.rear]=x;
    q.rear=(q.rear+1)%Maxsize;
        return true;
}
bool DeQ(Queue &q,elem &e)
{
    if(q.front==q.rear)
        return false;
    e=q.q[q.front];
    q.front=(q.front+1)%Maxsize;
        return true;
}
int QueueLength(Queue q)
{
    return(q.rear-q.front);
}
void Copy(Queue &q1,Queue &q2)
{
    elem e;
    while(QueueLength(q1)!=0)
    {
        DeQ(q1,e);
        EnQ(q2,e);
    }
}
void Print(Queue q)
{
    int i;
    for(i=q.front;i<q.rear;i++)
        printf("%d ",q.q[i]);
}