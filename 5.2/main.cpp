//算法
// 1.存在函数Max(A,n) A 数组的前n个元素的最大值
// 2.所求为MAX(Max(A,n-1),A[n])
#include <iostream>
int Max(int A[],int n)
{
    if(n==1)
        return A[0];
    if(Max(A,n-1)>A[n-1])
        return Max(A,n-1);
    else
        return A[n-1];
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("%d",Max(A,n));
}