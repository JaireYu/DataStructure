#include <iostream>
#include <string.h>
#define n 83
#define n1 73
typedef struct RAM{
    RAM * next;
    char str[10];
}RAM;

void InitRAM(RAM *& HushList) {
    HushList = (RAM *)malloc(sizeof(RAM));
    HushList->next = nullptr;
    HushList->str[0] = '\0';
}

int Hush(const char str[10]) {
    return ((str[6]-48)*(str[6]-48) + (str[7]-48) + 71*(str[8]-48)*(str[8]-48) + 20*(str[9]-48) + 81*(str[3]-48))%n;
}

void print(RAM * HushList[]) {
    int i;
    for(i = 0; i < n; i ++){
        printf("%d\t", i);
        RAM * p = HushList[i];
        while(p->next != nullptr){
            printf("%s   ", p->next->str);
            p = p->next;
        }
        printf("\n");
    }
}

void InsertRAM(RAM * HushList[]) {
    FILE * fp;
    if((fp = fopen("test.csv","r")) == NULL){
        printf("ERROR!!");
        exit(0);
    }
    char str[11];
    int i = 0;
    while(i < n1){
        RAM* p, *q;
        p = (RAM *)malloc(sizeof(RAM));
        fgets(str, 11, fp);
        if(fgetc(fp) == '\r')
            fseek(fp,1L,SEEK_CUR);
        q = HushList[Hush(str)]->next;
        p->next = nullptr;
        strcpy(p->str, str);
        if(q == nullptr)
            HushList[Hush(str)]->next = p;
        else{
            while(q->next != nullptr){
                q = q->next;
            }
            q->next = p;
        }
        i ++;
    }
    fclose(fp);
}

double Search(RAM * HushList[], const char * file){
    FILE * fp;
    if((fp = fopen(file,"r")) == NULL){
        printf("ERROR!!");
        exit(0);
    }
    char str[11];
    int i = 0;
    int count = 0;
    char c;
    while((c = fgetc(fp)) != EOF){
        fseek(fp, -1L, SEEK_CUR);
        RAM * p;
        fgets(str, 11, fp);
        if(fgetc(fp) == '\r')
            fseek(fp,1L,SEEK_CUR);
        p = HushList[Hush(str)]->next;
        count ++;
        if(p != nullptr) {
            while(p->next != nullptr) {
                if(strcmp(p->next->str,str) == 1)
                    break;
                count ++;
                p = p->next;
            }
        }
        i++;
    }
    fclose(fp);
    return float(count)/float(i);
}
int main() {
    int i;
    double a, b;
    RAM * HushList[n];
    for(i = 0; i < n; i ++){
        InitRAM(HushList[i]);
    }
    InsertRAM(HushList);
    print(HushList);
    a = Search(HushList,"fail.csv");
    b = Search(HushList,"success.csv");
    printf("The failure average search time m is %lf\n",a);
    printf("The success average search time n is %lf\n",b);
    printf("m + n = %lf", a + b);
    for(i = 0; i < n; i ++){
        delete HushList[i];
    }
}