#include <iostream>
#include <stdio.h>
#define elem char
#define maxsize 100
typedef struct {
    elem a[maxsize];
    int ListSize;
    int ListLength;
}S;
void Trans(S &la);
void InitList(S &la);
void ListInsert(S &la, int i,elem x);
void ListDelete(S &la,int i,elem &x);
void Traverse(S la,void (*visit)(elem));
void print(elem x);
int main()
{
    char m;
    S la;
    InitList(la);
    while((m=getchar())!='\n')
        ListInsert(la, 0, m);
    Trans(la);
    Traverse(la,print);
}
void InitList(S &la)
{
    la.ListLength=0;
    la.ListSize=maxsize;
}
void ListDelete(S &la,int i,elem &x)
{
    int j;
    x=la.a[i];
    for(j=i;j<la.ListLength-1;j++)
        la.a[j]=la.a[j+1];
    la.ListLength--;
}
void ListInsert(S &la, int i,elem x)
{
    int j;
    for(j=la.ListLength-1;j>=i;j--)
        la.a[j+1]=la.a[j];
    la.a[i]=x;
    la.ListLength++;
}
void Trans(S &la)
{
    char x;
    int m=0,i;
    for(m=0;m<la.ListLength;m++)
    {
        for(i = 0; i < la.ListLength-m;i++)
        {
            if(la.a[i]=='b')
            {
                ListDelete(la, i, x);
                ListInsert(la, la.ListLength, x);
                break;
            }

        }
    }
    Traverse(la,print);
    printf("\n");


}
void print(char x)
{
    printf("%c ",x);
}
void Traverse(S la, void (* visit)(elem))
{
    int i;
    for(i=0;i<la.ListLength;i++)
        visit(la.a[i]);
}