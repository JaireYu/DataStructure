#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MaxSize 100
typedef struct {
    char S[MaxSize];
}STRING;
int Index(STRING str,STRING pro,int pos);
bool StrInsert(STRING &str,int pos,STRING sub);
bool StrDelete(STRING &str,int pos,int len);
int StrLen(STRING str);
bool SubStr(STRING str, int pos, int len, STRING &sub);
void replace(STRING &str, STRING pro, STRING sub);
void print(STRING str);
int strcmp(STRING a,STRING b)
{
    int i=0,j=0;
    while(i<StrLen(a)&&j<StrLen(b))
    {
        if(a.S[i]>b.S[j]) return 1;
        if(a.S[i]<b.S[j]) return -1;
        i++;j++;
    }
    if(i<StrLen(a)) return 1;
    if(j<StrLen(b)) return -1;
    return 0;
}
int main()
{
    STRING str,sub,pro;
    scanf("%s",str.S);
    scanf("%s",pro.S);
    scanf("%s",sub.S);
    replace(str,pro,sub);
    print(str);
    return 0;
}
bool SubStr(STRING str, int pos, int len, STRING &sub)
{
    int i;
    if((pos+len)>StrLen(str))
        return false;
    else{
        for(i=0;i<len;i++)
            sub.S[i]=str.S[pos+i];
    }
    sub.S[len]='\0';
    return true;
}
int Index(STRING str, STRING pro, int pos)
{
    STRING sub;
    int i;
    for(i=pos;i<=StrLen(str)-StrLen(pro);i++)
    {
        SubStr(str,i,StrLen(pro),sub);
        if(strcmp(sub,pro)==0)
            return i;
    }
    return -1;
}
int StrLen(STRING str)
{
    int i=0;
    while(str.S[i]!='\0')
    {
        i++;
    }
    return i;
}
bool StrDelete(STRING &str, int pos, int len)
{
    int i;
    if(pos>StrLen(str))
        return false;
    else if(StrLen(str)<(pos+len))
        str.S[pos]='\0';
    else
    {
        for(i=pos+len;i<StrLen(str);i++)
        {
            str.S[i-len]=str.S[i];
        }
        str.S[StrLen(str)-len]='\0';
    }
    return true;
}
void replace(STRING &str, STRING pro, STRING sub)
{
    int i=Index(str,pro,0);
    if(i==-1)
    {
        printf("fault to change\n");
        return;
    }
    StrDelete(str,i,StrLen(pro));
    StrInsert(str,i,sub);
}
bool StrInsert(STRING &str,int pos,STRING sub)
{
    int i;
    if(pos>StrLen(str))
        return false;
    else {
        str.S[StrLen(str)+StrLen(sub)]='\0';
        for (i = StrLen(str)-1; i >= pos; i--)
            str.S[i + StrLen(sub)] = str.S[i];
        for (i = 0; i < StrLen(sub); i++)
            str.S[pos + i] = sub.S[i];
    }
    return true;
}
void print(STRING str)
{
    int i;
    for(i=0;i<StrLen(str);i++)
    {
        printf("%c",str.S[i]);
    }
    printf("\n");
}