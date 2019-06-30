#include <iostream>
#include <stdio.h>
#include <malloc.h>
typedef struct TNODE{
    char c;
    TNODE *pleft;
    TNODE *pright;
}TNODE;

void PrintTree(TNODE * root) {
    if(root == nullptr)
        return;
    printf("%c", root->c);
    PrintTree(root->pleft);
    PrintTree(root->pright);
}

void FreeTree(TNODE * root){
    if(root == nullptr)
        return;
    FreeTree(root->pleft);
    FreeTree(root->pright);
    free(root);
}

void DestoryTree(TNODE *&root) {
    FreeTree(root);
    root = nullptr;
}

void search(TNODE *pr, char py, TNODE *&p){
    if(pr == nullptr)
        return;
    if(pr->c == py){
        p = pr;
        return;
    }
    search(pr->pleft, py, p);
    search(pr->pright, py, p);
}

bool InsertBTchild(TNODE *pr, char py, char y, int flag){
    if(pr == nullptr||py == '*'||y == '*')
        return false;
    TNODE *p = nullptr;
    search(pr, py, p);
    if(p == nullptr)
        return false;
    if(flag == 0){
        if(p->pleft != nullptr)
            return false;
        else if(y == '*')
            p->pleft = nullptr;
        else{
            TNODE *q = (TNODE *)malloc(sizeof(TNODE));
            q->pleft = nullptr;
            q->pright = nullptr;
            q->c = y;
            p->pleft = q;
        }
    }
    if(flag == 1){
        if(p->pright != nullptr)
            return false;
        else if(y == '*')
            p->pright = nullptr;
        else{
            TNODE *q = (TNODE *)malloc(sizeof(TNODE));
            q->pleft = nullptr;
            q->pright = nullptr;
            q->c = y;
            p->pright = q;
        }
    }
}

void InitBTree(TNODE *&root, const char *s){
    int i = 0;
    root = (TNODE *)malloc(sizeof(TNODE));
    root->c = s[i];
    root->pleft = nullptr;
    root->pright = nullptr;
    i=i+2;
    while(s[i] != '#') {
        InsertBTchild(root, s[i], s[i+2], 0);
        InsertBTchild(root, s[i], s[i+4], 1);
        i += 6;
    }
}

void CopyBTree(TNODE *root, TNODE *&cpr) {
    if(root == nullptr){
        cpr = nullptr;
        return;
    }
    cpr = (TNODE *)malloc(sizeof(TNODE));
    cpr->c = root->c;
    CopyBTree(root->pleft, cpr->pleft);
    CopyBTree(root->pright, cpr->pright);
}


int main() {
    TNODE * root,* cpr;
    InitBTree(root, "A;A,B,C;B,D,E;C,F,G;D,*,*;E,*,*;F,*,*;G,*,*;#");
    PrintTree(root);
    CopyBTree(root, cpr);
    PrintTree(cpr);
    DestoryTree(root);
    DestoryTree(cpr);
    return 0;
}