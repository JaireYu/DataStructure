//前驱后继都做了
#include <iostream>
#include<stdio.h>
#define MaxListSize 100
#define elem int
typedef struct{
	elem a[MaxListSize];
	int ListSize;
	int ListLength;
}S;
void InitList(S &la);
bool ListInsert(S &la,int i, int x);
bool NextElem(S la,elem n,elem &m);
bool PriorElem(S la,elem p,elem &q);
void anti(S &la);
int main()
{
	elem x,p,q,n,m;
	char k;
    S la;
    InitList(la);
    printf("crate a list(space to separate and enter to end)\n");
    while(1)
    {
        scanf("%d",&x);
        k=getchar( );
    	ListInsert(la,0,x);
    	if(k=='\n')
    	    break;
    }
    anti(la);
    printf("enter an element\n");
    scanf("%d",&p);
    if(PriorElem(la,p,q)==true)
        printf("Its prior element is %d\n",q);
    else
        printf("It has no prior element\n");
    if(NextElem(la,p,m)==true)
        printf("Its next element is %d\n",m);
    else
        printf("It has no next element\n");
}
void InitList(S &la)
{
	la.ListSize = MaxListSize;
	la.ListLength = 0;
}
bool PriorElem(S la,elem p,elem &q)
{
    int i;
	if(p==la.a[0])
	    return false;
	else
	{
	    for(i=1;i<la.ListLength;i++)
		{
			if(p==la.a[i])
			{
			    q=la.a[i-1];
				return true;
			}
		}
		return false;
	}
}
bool NextElem(S la,elem n,elem &m)
{
    int i;
	if(n==la.a[la.ListLength-1])
	    return false;
	else
	{
	    for(i=0;i<la.ListLength-1;i++)
		{
			if(n==la.a[i])
			{
			    m=la.a[i+1];
				return true;
			}
		}
		return false;
	}
}
bool ListInsert(S &la,int i,elem x)
{
    int j;
    if((i<0)||(i>la.ListLength)||(la.ListLength>=la.ListSize))
        return false;
    for(j=la.ListLength-1;j>=i;j--)
        la.a[j+1]=la.a[j];
    la.a[i]=x;
    la.ListLength++;
    return true;
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