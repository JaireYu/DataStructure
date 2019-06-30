//算法
//1.遍历顺序表找出插入点
//2.插入该值
#include <iostream>
#include <stdio.h>
#define MaxSize 100
#define elem int
typedef struct{
    elem a[MaxSize];
    int ListLength;
    int ListSize;
}S;
void InitList(S &la);
void Traverse(S &la,elem a);
void ListInsert(S &la, int i, elem a);
void Tranprint(S la);
void anti(S &la);
int main()
{
    S la;
    elem a,x;
    char m;
    InitList(la);
    printf("create a list in a not down way (space to separate and enter to end)\n");
    while(1)
    {
        scanf("%d", &x);
        m = getchar();
        ListInsert(la, 0, x);
        if (m == '\n')
            break;
    }
    anti(la);
    printf("input the number which you want in\n");
    scanf("%d",&a);
    Traverse(la,a);
    Tranprint(la);
}
void InitList(S &la)
{
    la.ListSize=MaxSize;
    la.ListLength=0;
}
void ListInsert(S &la, int i, elem a)
{
    int j;
    for(j=la.ListLength-1;j>=i;j--)
    {
        la.a[j+1]=la.a[j];
    }
    la.a[i]=a;
    la.ListLength++;
}
void Traverse(S &la,elem a)
{
    int i;
    int flag=0;
    if(a<la.a[0])
    {
        ListInsert(la,0,a);
        return;
    }
    if(a>la.a[la.ListLength-1])
    {
        ListInsert(la,la.ListLength,a);
        return;
    }
    for(i=0;i<la.ListLength-1;i++)
    {
        if((a>=la.a[i])&&(a<=la.a[i+1]))
        {
            ListInsert(la, i + 1, a);
            break;
        }
    }
}
void Tranprint(S la)
{
    int i;
    for(i=0;i<la.ListLength;i++)
        printf("%d ",la.a[i]);
}
void anti(S &la)
{
    int i;
    elem temp;
    for(i=0;i<la.ListLength/2;i++)
    {
        temp=la.a[i];
        la.a[i]=la.a[la.ListLength-i-1];
        la.a[la.ListLength-i-1]=temp;
    }
}