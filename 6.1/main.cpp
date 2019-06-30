#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MaxSize 100
typedef struct {
    char S[MaxSize];
}STRING;
bool StrDelete(STRING &str, int pos, int len);
int StrLen(STRING str);
void print(STRING str);
int main()
{
    STRING str;
    scanf("%s",str.S);
    int pos,len;
    scanf("%d %d",&pos,&len);
    if(StrDelete(str,pos,len)==true)
        print(str);
    else
        printf("ERROR\n");
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
void print(STRING str)
{
    int i;
    for(i=0;i<StrLen(str);i++)
    {
        printf("%c",str.S[i]);
    }
    printf("\n");
}