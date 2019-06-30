#include <iostream>
#define Maxsize 100
#define elem int
typedef struct {
    elem q[Maxsize];
    int front,rear;
}Queue;
void InitQ(Queue &q);
bool EnQ(Queue &q,elem x);
int QueueLength(Queue q);
int main() {
    Queue q;
    InitQ(q);
    elem x;char c='1';
    printf("create a list ' ' to divide and '\\n' to stop\n");
    while(c!='\n')
    {
        scanf("%d",&x);
        c=getchar();
        EnQ(q,x);
    }
    printf("%d",QueueLength(q));
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
}
int QueueLength(Queue q)
{
    return(q.rear-q.front);
}