//算法
//1.设置左标号l=0和右标号r=la.ListLength
//2.比较左右标号对应的元素
//  只有四种情况
//   1)奇奇 r=r;l++;
//   2)偶偶 l=l;r--;
//   3)奇偶 l++;r--;
//   4)偶奇 交换位置 l++;r--;
//3.执行以上操作直至l=r 完成奇偶排序
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
bool Judge(elem a);
void ListInsert(S &la,int i,elem x);
void Order(S &la);
void Print(S la);
int main() {
    S la;
    InitList(la);
    char m;
    elem x;
    printf("Create you array(separate them with ' ' and end with a '\\n'\n");
    for(m='1';m!='\n';)
    {
        scanf("%d",&x);
        m=getchar();
        ListInsert(la,0,x);
    }
    Order(la);
    Print(la);
}
void InitList(S &la)
{
    la.ListLength=0;
    la.ListSize=MaxSize;
}
bool Judge(elem a)
{
    if(a%2==0)
        return true;//偶数
    else
        return false;//奇数
}
void ListInsert(S &la,int i,elem x)
{
    int j;
    for(j=la.ListLength-1;j>=i;j--)
    {
        la.a[j+1]=la.a[j];
    }
    la.a[i]=x;
    la.ListLength++;
}
void Order(S &la)
{
    int l=0,r=la.ListLength-1;
    elem temp;
    while(l<r)
    {
        if((Judge(la.a[l])==true)&&(Judge(la.a[r])==true)){
            r--;
        } else if((Judge(la.a[l])==false)&&(Judge(la.a[r])==true)){

            r--; l++;
        } else if((Judge(la.a[l])==true)&&(Judge(la.a[r])==false))
        {
            temp=la.a[l];
            la.a[l]=la.a[r];
            la.a[r]=temp;
            r--;l++;
        } else {
            l++;
        }
    }
}
void Print(S la)
{
    int i;
    for(i=0;i<la.ListLength;i++)
        printf("%d ",la.a[i]);
}