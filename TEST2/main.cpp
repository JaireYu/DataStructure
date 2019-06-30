#include <iostream>
#include<stdlib.h>
//#include<malloc.h>
//#include <process.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int *maxlen;
    int *xpos;
    int *ypos;
    int size;
    int MaxSize;
}LIST;
void Initlist(LIST &S);
void AgainMalloc(LIST &S);
void ListInsert(LIST &S, int a, int b, int c);
bool GetMartix(char **&C, char *str1, char *str2);
void GetDiag(char **C,char* str1,char* str2, LIST &S);
void printlist(LIST &S);
void GetMaxLen(LIST &S, int &xmax, int &ymax, int &lenmax);
void GetMaxsubstr(char *&sub, const char *str1,int xmax,int lenmax);
void StrDelete(char *&str, int pos, int len);
double matchS(char *str1, char*str2);//求句子相似度
void readin1(char ***&C,int &pmax,int &smax,int &cmax);//将文章读入三维数组， pmax，smax，cmax分别为其段落，句子，字符的最长标号
void readin2(char ***&A,int &pmax,int &smax,int &cmax);
double AriMatch(int Apmax,int Bpmax,int Asmax,int Bsmax, int Acmax, int Bcmax, char ***A,char ***B);//求文章相似度
double ParaMatch(char **A, char**B,int Asmax,int Bsmax, int Acmax, int Bcmax);//求段落相似度
int main() {
    char ***A;
    int Apmax=0;
    int Asmax=0;
    int Acmax=0;
    readin1(A,Apmax,Asmax,Acmax);
    //printf("%c",A[1][0][0]);
    char ***B;
    int Bpmax=0;
    int Bsmax=0;
    int Bcmax=0;
    readin2(B,Bpmax,Bsmax,Bcmax);
    //printf("%c",B[1][0][0]);
    float m=float(100*AriMatch(Apmax,Bpmax,Asmax,Bsmax,Acmax,Bcmax,A,B));
    //printf("%lf",matchS(A[2][0],B[1][0]));
    int i,j;
    for(i = 0; i <= Apmax; ++i)
      for(j = 0; j <= Asmax; ++j)
        free(A[i][j]);
    for(i = 0; i <= Apmax; ++i)
      free(A[i]);
    free(A);
    for(i = 0; i <= Bpmax; ++i)
      for(j = 0; j <= Bsmax; ++j)
        free(B[i][j]);
    for(i = 0; i <= Bpmax; ++i)
      free(B[i]);
    free(B);
    printf("%.2f%%",m);
}
bool GetMartix(char **&C, char *str1, char *str2)
{
    int i,j;
    if(C!=NULL)
    {
        //delete(C);
        C=NULL;
    }
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(strlen(str1)==0||strlen(str2)==0)
        return false;
    C=(char **)malloc(strlen(str1)*sizeof(char *));
    for(i=0;i<strlen(str1);i++ )
    {
        *(C+i)=(char *)malloc(strlen(str2)*sizeof(char));
        for (j=0;j<strlen(str2);j++)
        {
            if (*(str1+i)==*(str2+j))
                *(*(C+i)+j) = '1';
            else
                *(*(C+i)+j) = '0';
        }
    }
    return true;
}

void Initlist(LIST &S)
{
    if(S.maxlen!=NULL)
    {
        S.maxlen=NULL;
    }
    if(S.xpos!=NULL)
    {
        S.xpos=NULL;
    }
    if(S.ypos!=NULL)
    {
        S.ypos=NULL;
    }
    S.maxlen=(int *)malloc(sizeof(int));
    S.xpos=(int *)malloc(sizeof(int));
    S.ypos=(int *)malloc(sizeof(int));
    S.MaxSize=1;
    S.size=0;
}

void GetDiag(char **C,char* str1,char* str2, LIST &S)
{
    int i,j,r,c=0,count=0;
    int len1=strlen(str1);
    int len2=strlen(str2);
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(C[i][j]=='1')
            {
                count=0;
                c=i;r=j;
                while(C[c][r]=='1')
                {
                    count++;
                    C[c][r] = '2';
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
    S.maxlen=(int *)realloc(S.maxlen,(S.MaxSize+1)* sizeof(int));
    S.xpos=(int *)realloc(S.xpos,(S.MaxSize+1)* sizeof(int));
    S.ypos=(int *)realloc(S.ypos,(S.MaxSize+1)* sizeof(int));
    S.MaxSize++;
}

void ListInsert(LIST &S, int a, int b, int c)
{
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

void GetMaxsubstr(char *&sub,const char *str1,int xmax,int lenmax)
{
    int i;
    if(sub!=NULL)
    {
        sub=NULL;
    };
    sub=(char *)malloc(sizeof(char)*lenmax);
    for(i=0;i<lenmax;i++)
    {
        sub[i]=str1[xmax+i];
    }
}

void StrDelete(char *&str, int pos, int len)
{
    int i;
    for(i=pos+len;i<strlen(str);i++)
    {
        str[i-len]=str[i];
    }
    str[strlen(str)-len]='\0';
}

double matchS(char *str1, char *str2)
{
    char **C;
    //char *sub;
    LIST S;
    Initlist(S);
    int xmax=0,ymax=0,lenmax=0,count=0;
    int len;
    if(strlen(str1)>strlen(str2))
        len=strlen(str2);
    else
        len=strlen(str1);
    if(GetMartix(C,str1,str2)==false)
        return 0;
    GetDiag(C,str1,str2,S);
    GetMaxLen(S, xmax, ymax, lenmax);
    //GetMaxsubstr(sub,str1,xmax,lenmax);
    StrDelete(str1,xmax,lenmax);
    StrDelete(str2,ymax,lenmax);
    count=count+lenmax;
    while(lenmax!=0)
    {
        Initlist(S);
        if(GetMartix(C,str1,str2)==false)
            break;
        GetDiag(C,str1,str2,S);
        GetMaxLen(S, xmax, ymax, lenmax);
        //GetMaxsubstr(sub,str1,xmax,lenmax);
        StrDelete(str1,xmax,lenmax);
        StrDelete(str2,ymax,lenmax);
        count=count+lenmax;
    }
    int i;
    if(C!=NULL){
    for(i=0;i<strlen(str1);i++)
        free(C[i]);
    free(C);
    }
    delete S.xpos;
    delete S.ypos;
    delete S.maxlen;
    return float(count)/float(len);
}
void readin1(char ***&C,int &pmax,int &smax,int &cmax)
{
    FILE *fp;
    char ch;
    int flag,start=0,ctemp=0,stemp=0,i,j,k;
    C=(char ***)malloc(sizeof(char **));
    C[0]=(char **)malloc(sizeof(char *));
    C[0][0]=(char *)malloc(sizeof(char));
    if((fp=fopen("D:\\C language learn\\TEST2\\cmake-build-debug\\test1.txt","r+"))==NULL){
        printf("cannot open the file\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' '&&start==0)
            flag=0;
        else if(ch=='.')
        {   flag=2;
            start=0;
        }
        else if(ch=='\n')
        {
            flag=3;
            start=0;
        }
        else
        {
            flag=1;
            if(ch==',') start=0;
            else start=1;
        }
        switch(flag){
            case 0: break;
            case 1: {
                C[pmax][stemp][ctemp]=ch;
                ctemp++;
                if(ctemp>cmax)
                {
                    cmax++;
                    C=(char ***)realloc(C,(pmax+1)*sizeof(char **));
                    C=(char ***)realloc(C,(pmax+1)*sizeof(char **));
                    for(i=0;i<=pmax;i++) {
                        C[i] = (char **) realloc(C[i], (smax + 1) * sizeof(char *));
                        C[i] = (char **) realloc(C[i], (smax + 1) * sizeof(char *));
                    }
                    for(i=0;i<=pmax;i++)
                        for(j=0;j<=smax;j++) {
                            C[i][j] = (char *) realloc(C[i][j], (cmax + 1) * sizeof(char));
                            C[i][j] = (char *) realloc(C[i][j], (cmax + 1) * sizeof(char));
                        }
                }
            }
                break;
            case 2: {
                C[pmax][stemp][ctemp]='\0';
                ctemp=0;
                stemp++;
                if(stemp>smax) {
                    smax++;
                    C = (char ***) realloc(C, (pmax + 1) * sizeof(char **));
                    C = (char ***) realloc(C, (pmax + 1) * sizeof(char **));
                    for (i = 0; i <= pmax; i++)
                    {
                        C[i] = (char **) realloc(C[i], (smax+ 1) * sizeof(char *));
                        C[i] = (char **) realloc(C[i], (smax+ 1) * sizeof(char *));
                    }
                    for (i = 0; i <= pmax; i++)
                        for (j = 0; j <= smax; j++){
                            C[i][j] = (char *) realloc(C[i][j], (cmax + 1) * sizeof(char));
                            C[i][j] = (char *) realloc(C[i][j], (cmax + 1) * sizeof(char));
                        }
                }
            }
                break;
            default: {
                C[pmax][stemp][0]='\0';
                stemp=0;
                pmax++;
                C=(char ***)realloc(C,(pmax+1)*sizeof(char **));
                C=(char ***)realloc(C,(pmax+1)*sizeof(char **));
                for(i=0;i<=pmax;i++)
                { C[i]=(char **)realloc(C[i],(smax+1)*sizeof(char *));
                    C[i]=(char **)realloc(C[i],(smax+1)*sizeof(char *));}
                for(i=0;i<=pmax;i++)
                    for(j=0;j<=smax;j++)
                    {C[i][j]=(char *)realloc(C[i][j],(cmax+1)*sizeof(char ));
                        C[i][j]=(char *)realloc(C[i][j],(cmax+1)*sizeof(char ));
                    }
            }
        }
    }
    C[pmax][stemp][0]='\0';
    fclose(fp);
}
void readin2(char ***&A,int &pmax,int &smax,int &cmax)
{
    FILE *fp;
    char ch;
    int flag,start=0,ctemp=0,stemp=0,i,j,k;
    A=(char ***)malloc(sizeof(char **));
    A[0]=(char **)malloc(sizeof(char *));
    A[0][0]=(char *)malloc(sizeof(char));
    if((fp=fopen("D:\\C language learn\\TEST2\\cmake-build-debug\\test2.txt","r+"))==NULL){
        printf("cannot open the file\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' '&&start==0)
            flag=0;
        else if(ch=='.')
        {   flag=2;
            start=0;
        }
        else if(ch=='\n')
        {
            flag=3;
            start=0;
        }
        else
        {
            flag=1;
            if(ch==',') start=0;
            else start=1;
        }
        switch(flag){
            case 0: break;
            case 1: {
                A[pmax][stemp][ctemp]=ch;
                ctemp++;
                if(ctemp>cmax)
                {
                    cmax++;
                    A=(char ***)realloc(A,(pmax+1)*sizeof(char **));
                    A=(char ***)realloc(A,(pmax+1)*sizeof(char **));
                    for(i=0;i<=pmax;i++)
                    { A[i]=(char **)realloc(A[i],(smax+1)*sizeof(char *));
                        A[i]=(char **)realloc(A[i],(smax+1)*sizeof(char *));
                    }
                    for(i=0;i<=pmax;i++)
                        for(j=0;j<=smax;j++) {
                            A[i][j] = (char *) realloc(A[i][j], (cmax + 1) * sizeof(char));
                            A[i][j] = (char *) realloc(A[i][j], (cmax + 1) * sizeof(char));
                        }
                }
            }
                break;
            case 2: {
                A[pmax][stemp][ctemp]='\0';
                ctemp=0;
                stemp++;
                if(stemp>smax) {
                    smax++;
                    A = (char ***) realloc(A, (pmax + 1) * sizeof(char **));
                    A = (char ***) realloc(A, (pmax + 1) * sizeof(char **));
                    for (i = 0; i <= pmax; i++)
                    {
                        A[i] = (char **) realloc(A[i], (smax+ 1) * sizeof(char *));
                        A[i] = (char **) realloc(A[i], (smax+ 1) * sizeof(char *));
                    }
                    for (i = 0; i <= pmax; i++)
                        for (j = 0; j <= smax; j++){
                            A[i][j] = (char *) realloc(A[i][j], (cmax + 1) * sizeof(char));
                            A[i][j] = (char *) realloc(A[i][j], (cmax + 1) * sizeof(char));
                        }
                }
            }
                break;
            default: {
                A[pmax][stemp][0]='\0';
                stemp=0;
                pmax++;
                A=(char ***)realloc(A,(pmax+1)*sizeof(char **));
                A=(char ***)realloc(A,(pmax+1)*sizeof(char **));
                for(i=0;i<=pmax;i++)
                { A[i]=(char **)realloc(A[i],(smax+1)*sizeof(char *));
                    A[i]=(char **)realloc(A[i],(smax+1)*sizeof(char *));}
                for(i=0;i<=pmax;i++)
                    for(j=0;j<=smax;j++)
                    {A[i][j]=(char *)realloc(A[i][j],(cmax+1)*sizeof(char ));
                        A[i][j]=(char *)realloc(A[i][j],(cmax+1)*sizeof(char ));
                    }
            }
        }
    }
    A[pmax][stemp][0]='\0';
    fclose(fp);
}
double AriMatch(int Apmax,int Bpmax,int Asmax,int Bsmax, int Acmax, int Bcmax, char ***A,char ***B)
{
    int i=0,j=0;
    double count=0,temp,para;
    for(i=0;i<=Apmax;i++){
        temp=0;
        for(j=0;j<=Bpmax;j++)
        {
            if((para=ParaMatch(A[i],B[j],Asmax,Bsmax,Acmax,Bcmax))>temp)
                temp=para;
        }
        count=count+temp;
    }
    if(i>j)
        return double(count/i);
    else
        return double(count/j);
}
double ParaMatch(char **A, char**B,int Asmax,int Bsmax, int Acmax, int Bcmax)
{
    int i=0,j=0;
    double count=0,temp=0,s;
    char *str1=NULL;
    char *str2=NULL;
    for(i=0;i<=Asmax;i++){
        if(A[i][0]=='\0')
            break;
        temp=0;
        for(j=0;j<=Bsmax;j++){
            if(B[j][0]=='\0')
                break;
            str1=(char *)malloc(strlen(A[i])*sizeof(char));
            strcpy(str1,A[i]);
            str2=(char *)malloc(strlen(B[j])* sizeof(char));
            strcpy(str2,B[j]);
            if((s=matchS(str1,str2))>temp)
            {
                temp=s;
            }
        }
        count+=temp;
    }
    str1=NULL;
    str2=NULL;
    if(i>j)
        return double(count/i);
    else
        return double(count/j);
}