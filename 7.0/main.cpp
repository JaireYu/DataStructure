//四个都做
#include <iostream>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int *maxlen;
    int *xpos;
    int *ypos;
    int size;      //当前长度
    int MaxSize;
}LIST;
void Initlist(LIST &S);
void AgainMalloc(LIST &S);
void ListInsert(LIST &S, int a, int b, int c);
void GetMartix(char **&A, char *str1, char *str2);
void GetDiag(char **A,char* str1,char* str2, LIST &S);
void printlist(LIST &S);
void GetMaxLen(LIST &S, int &xmax, int &ymax, int &lenmax);
void GetMaxsubstr(char *&sub, char *str1,int xmax,int lenmax);
int main() {
    LIST S;
    int i,j;
    int xmax,ymax,lenmax;
    char **A;
    char *sub;
    char str1[]="china",str2[]="chima";
    Initlist(S);
    GetMartix(A,str1,str2);
    GetDiag(A,str1,str2,S);
    GetMaxLen(S, xmax, ymax, lenmax);
    GetMaxsubstr(sub,str1,xmax,lenmax);
    for(i=0;i<lenmax;i++)
    {
        printf("%c",sub[i]);
    }
    char str3[]="abcde";
    char str4[] ="abfff";
    Initlist(S);
    GetMartix(A,str3,str4);
    GetDiag(A,str3,str4,S);
    GetMaxLen(S, xmax, ymax, lenmax);
    GetMaxsubstr(sub,str3,xmax,lenmax);
    for(i=0;i<lenmax;i++)
    {
        printf("%c",sub[i]);
    }
    return 0;
}
void GetMartix(char **&A, char *str1, char *str2)
{
    int i,j;
    delete A;
    A=(char **)malloc(strlen(str1)*sizeof(char *));
    for(i=0;i<strlen(str1);i++ )
    {
        *(A+i)=(char *)malloc(strlen(str2)*sizeof(char));
        for (j=0;j<strlen(str2);j++)
        {
            if (*(str1+i)==*(str2+j))
                *(*(A+i)+j) = '1';
            else
                *(*(A+i)+j) = '0';
        }
    }
}
void Initlist(LIST &S)
{
    free(S.maxlen);
    free(S.xpos);
    free(S.ypos);
    S.maxlen=(int *)malloc(sizeof(int));
    S.xpos=(int *)malloc(sizeof(int));
    S.ypos=(int *)malloc(sizeof(int));
    S.MaxSize=1;
    S.size=0;
}
void GetDiag(char **A,char* str1,char* str2, LIST &S)
{
    int i,j,r,c=0,count=0;
    int len1=strlen(str1);
    int len2=strlen(str2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(A[i][j]=='1')
            {
                count=0;
                c=i;r=j;
                while(A[c][r]=='1')
                {
                    count++;
                    A[c][r] = '2';
                    c++;r++;
                    if(c>=len1||r>=len2)
                        break;
                }
                ListInsert(S,i,j,c-i);
            }

        }
    }
}
void AgainMalloc(LIST &S)
{
    realloc(S.maxlen,(S.MaxSize+1)* sizeof(int));//realloc 必须对已经malloc的指针使用
    realloc(S.xpos,(S.MaxSize+1)* sizeof(int));
    realloc(S.ypos,(S.MaxSize+1)* sizeof(int));
    S.MaxSize++;
}
void ListInsert(LIST &S, int a, int b, int c)
{
    int i;
    if (S.size == S.MaxSize)
        AgainMalloc(S);
    S.xpos[S.size] = a;
    S.ypos[S.size] = b;
    S.maxlen[S.size] = c;
    S.size++;
}
void printlist(LIST &S)
{
    int i;
    for(i=0;i<S.size;i++)
        printf("%d ",S.maxlen[i]);
}
void GetMaxLen(LIST &S, int &xmax, int &ymax, int &lenmax)
{
    int i;
    lenmax=0;xmax=0;ymax=0;
    for(i=0; i<S.size; i++)
    {
        if(S.maxlen[i]>lenmax)
        {
            lenmax=S.maxlen[i];
            xmax=S.xpos[i];
            ymax=S.ypos[i];
        }
    }
}
void GetMaxsubstr(char *&sub, char *str1,int xmax,int lenmax)
{
    int i;
    free(sub);
    sub=(char *)malloc(sizeof(char)*strlen(str1));
    for(i=0;i<lenmax;i++)
    {
        sub[i]=str1[xmax+i];
    }
}