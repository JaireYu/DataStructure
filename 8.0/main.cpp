#include <iostream>
#define MaxSize 100
typedef struct{
    int i,j;
    int e;
}Triple;
typedef struct{
    Triple data[MaxSize];
    int mu,nu,tu;
}Matrix;
void InitMatrix(Matrix &A);
void TripleInsert(Matrix &A,int i,int j,int e);
bool Add(Matrix A,Matrix B,Matrix &C);
void print(Matrix C);
int main() {
    Matrix A,B,C;
    InitMatrix(A);
    InitMatrix(B);
    InitMatrix(C);
    int Atu,Btu,i,a,b,c;
    printf("请输入A的非零元数\n");
    scanf("%d",&Atu);
    printf("请输入B的非零元数\n");
    scanf("%d",&Btu);
    printf("请输入A的三元组顺序表\n");
    for(i=0;i<Atu;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        TripleInsert(A,a,b,c);
    }
    printf("请输入B的三元组顺序表\n");
    for(i=0;i<Btu;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        TripleInsert(B,a,b,c);
    }
    Add(A,B,C);
    printf("其和为：\n");
    print(C);
    return 0;
}
void InitMatrix(Matrix &A)
{
    A.mu=30;
    A.nu=30;
    A.tu=0;
}
void TripleInsert(Matrix &A,int i,int j,int e)
{
    A.data[A.tu].j=j;
    A.data[A.tu].i=i;
    A.data[A.tu].e=e;
    A.tu++;
}
bool Add(Matrix A,Matrix B,Matrix &C)
{
    int m=0,n=0,a;
    if(A.mu!=B.mu||A.nu!=B.nu)
        return false;
    C.mu=A.mu;
    C.nu=A.nu;
    while(m<A.tu&&n<B.tu) {
        if(A.data[m].i<B.data[n].i)
        {
             TripleInsert(C,A.data[m].i,A.data[m].j,A.data[m].e);
             m++;
        }
        else if(A.data[m].i>B.data[n].i)
        {
             TripleInsert(C,B.data[n].i,B.data[n].j,B.data[n].e);
             n++;
        }
        else
        {
             if(A.data[m].j<B.data[n].j)
             {
                 TripleInsert(C,A.data[m].i,A.data[m].j,A.data[m].e);
                 m++;
             }
             else if(A.data[m].j<B.data[n].j)
             {
                 TripleInsert(C,B.data[n].i,B.data[n].j,B.data[n].e);
                 n++;
             }
             else
             {
                 TripleInsert(C,B.data[n].i,B.data[n].j,B.data[n].e+A.data[m].e);
                 m++;n++;
             }
        }
    }
    if(m<A.tu)
    {
       for(a=m;a<A.tu;a++)
           TripleInsert(C,A.data[a].i,A.data[a].j,A.data[a].e);
    }
    else if(n<B.tu)
    {
        for(a=m;a<B.tu;a++)
            TripleInsert(C,B.data[a].i,B.data[a].j,B.data[a].e);
    }
    return true;
}
void print(Matrix C)
{
    int i;
    for(i=0;i<C.tu;i++)
    {
        printf("%d %d %d\n",C.data[i].i,C.data[i].j,C.data[i].e);
    }
}