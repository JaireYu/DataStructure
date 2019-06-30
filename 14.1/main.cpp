#include <iostream>
typedef struct NODE {
    NODE * next;
    int num;
}NODE;
void CreateNode(NODE * &pHead);
void SortNode(NODE * &pHead);
void Print(NODE * pHead);
void DeleteNode(NODE * &pHead, NODE * tempPtr, NODE * tempPts);
void InsertNode(NODE * &pHead, NODE * tempPtr, NODE * p, NODE *q);
int main() {
    NODE * pHead;
    CreateNode(pHead);
    SortNode(pHead);
    Print(pHead);
    delete(pHead);
    return 0;
}
void CreateNode(NODE * &pHead) {
    int i;
    NODE * p;
    printf("please input you list (int) with a '#' as an end:\n");
    pHead = (NODE *)malloc(sizeof(NODE));
    pHead -> next = nullptr;
    while(scanf("%d", &i)) {
        p = (NODE *)malloc(sizeof(NODE));
        p -> next = pHead -> next;
        pHead -> next = p;
        p -> num = i;
    }
}
void SortNode(NODE * &pHead) {
    NODE * p, *q,*tempPtr, *r, *s, *tempPts;
    int temp;
    q = pHead;
    p = q->next;
    while (p ->next) {
        r = p;s = q;
        temp = r ->num;
        tempPtr = r;
        tempPts = s;
        while(s ->next) {
            if(r ->num < temp) {
                tempPtr = r;
                tempPts = s;
                temp = r->num;
            }
            r = r->next;
            s = s->next;
        }
        if(tempPtr != p){
            DeleteNode(pHead, tempPtr, tempPts);
            InsertNode(pHead, tempPtr, p, q);
        }
        q = q ->next;
        p = q ->next;
    }

}
void DeleteNode(NODE * &pHead, NODE * tempPtr, NODE * tempPts) {
    tempPts->next = tempPtr->next;
}
void InsertNode(NODE * &pHead, NODE * tempPtr, NODE * p, NODE *q) {
    q->next = tempPtr;
    tempPtr->next = p;
}
void Print(NODE * pHead) {
    NODE * p;
    p = pHead ->next;
    while(p) {
        printf("%d ", p->num);
        p = p->next;
    }
}