#include <iostream>
#include <stdio.h>
#define MaxSize 100
int Position (int *A,int x);
int main() {
    int num[MaxSize]={0};
    int x,i,position;
    char m;
    printf("Create you array(separate them with ' ' and end with a '\\n'\n");
    for(m='1',i=0;m!='\n';i++)
    {
        scanf("%d",&x);
        m=getchar();
        num[i]=x;
    }
    printf("enter x\n");
    scanf("%d",&x);
    position=Position(num,x);
    printf("The position is %d",position);
}
int Position (int *A,int x)
{
    int i,j=0,k;
    for(i=0;A[i]!='\0';i++)//i=len 数组从0-i-1
    {}
    while(j<i)
    {
        if(A[j]<=x)
            j++;
        else{
            for(k=j;k<i;k++)
            {
                if(A[k]<=x)
                    return -2;
            }
            return j-1;
        }
    }
    return j-1;
}
