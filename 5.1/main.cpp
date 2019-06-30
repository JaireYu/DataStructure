//背包问题
//算法
// 1.不断入栈直至最后物品，不符合条件的就弹出，入下一个
// 2.背包里有最后一个元素且还有两个及以上物品，弹栈两次回溯
// 3.否则弹栈一次回溯
// 4.单独最后一个元素未考虑，单独考虑
// 5.输出结果

#include <iostream>
#include <stdio.h>
#define elem int
#define maxsize 100
typedef struct {
    elem st[maxsize];
    int top;
}steak;
steak S;
char rec[1000]={'0'};//用来存放结果
void InitSteak(steak &S);
int Total(steak S,int w[]);//计算背包中元素的总体积
void push(steak &S,elem e);
bool pop(steak &S,elem &e);
void writein(char rec[],steak S,int n);//写入符合的结果
void rewrite(char rec[],steak S,int n);//发现更好结果重写
void Initrec(char rec[]);//初始化rec串
void print(char rec[],int n);//打印结果
void knapsack(int w[], int n, int T);
int main()
{
    int i,n,T;
    printf("enter n T\n");
    scanf("%d %d",&n,&T);
    int w[n];
    InitSteak(S);
    Initrec(rec);
    printf("enter package element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    knapsack(w,n,T);
    print(rec,n);
}

void InitSteak(steak &S)
{
    S.top=0;
}

int Total(steak S,int w[])
{
    int sum=0,i;
    for(i=0;i<S.top;i++)
        sum=sum+w[S.st[i]];
    return sum;
}

void push(steak &S,elem e)
{
    S.st[S.top]=e;
    S.top++;
}

bool pop(steak &S,elem &e)
{
    if(S.top==0)
        return false;
    S.top--;
    e=S.st[S.top];
    return true;
}

void writein(char rec[],steak S,int n)
{
    int i,j;
    for(i=0;;i++)
    {
        if(rec[i]=='#')
            break;
    }
    for(j=0;j<n;j++)
    {
        rec[i+j]='0';
    }
    for(j=0;j<S.top;j++)
    {
        rec[i+S.st[j]]='1';
    }
    rec[i+n]='#';
}

void rewrite(char rec[],steak S,int n)
{
    int j;
    for(j=0;rec[j]!='#';j++)
    {
        rec[j]='0';
    }
    for(j=0;j<n;j++)
    {
        rec[j]='0';
    }
    for(j=0;j<S.top;j++)
    {
        rec[S.st[j]]='1';
    }
    rec[n]='#';
}

void Initrec(char rec[])
{
    rec[0]='#';
}

void print(char rec[],int n)
{
    int i;
    for(i=0;rec[i]!='#';i++)
    {
        if(i%n==0) printf("\n");
        printf("%c ",rec[i]);
    }
}

void knapsack(int w[], int n, int T)
{
    int k=0,e,i,flag,temp=0;
    InitSteak(S);
    push(S,k);
    while((S.top!=0)||(flag==1))
    {
        flag=0;
        while(1)
        {
            if(Total(S,w)>T) //最大可能地放入背包 直至最后
                pop(S,e);
            if(k==(n-1))
                break;
            k++;
            push(S,k);
        }
        if(Total(S,w)<=T&&Total(S,w)==temp)//找到另一组解
        {
            writein(rec,S,n);
        }
        else if((Total(S,w)<=T)&&(Total(S,w)>temp))//找到更优解
        {
            temp=Total(S,w);
            rewrite(rec,S,n);
        }
        if(S.top!=0)
        {
            if ((S.st[S.top-1]==(n-1))&&( S.top>1))//结尾是最后一个物品 弹栈两次（这种情况下栈空了不作为while结束的条件）
            {
                pop(S,e);
                k=S.st[S.top-1];
                pop(S,e);
                if(S.top==0)
                {
                    flag=1;
                }
            }
            else//结尾不是最后一个物品 或者栈内只有一个元素 弹栈一次
            {
                k=S.st[S.top-1];
                pop(S,e);
            }
        }
    }
    InitSteak(S);//单独考虑最后元素
    push(S,n-1);
    if(Total(S,w)<=T&&Total(S,w)==temp) {writein(rec,S,n); }
    else if(Total(S,w)<=T&&Total(S,w)>temp) {rewrite(rec,S,n);}
}