#include <iostream>
#include <stdio.h>
#include <malloc.h>
typedef struct TNODE{
    TNODE * pchild;
    TNODE * psibling;
    char c;
}TNODE;
bool GenTree(TNODE * &root, const char *s) {
    TNODE *p=nullptr;
    int i;
    if(s[0] == '\0')
        return false;
    root -> psibling = nullptr;
    root -> pchild = nullptr;
    root -> c = s[0];
    for(i = 0; s[i] != '\0';i++){

    }
    i--;
    while(i > 0){
        p = (TNODE*)malloc(sizeof(TNODE));
        p -> c = s[i];
        p -> psibling = root->pchild;
        root -> pchild =  p;
        p -> pchild = nullptr;
        i --;
    }
    return true;

}
void PrintTree(TNODE * root)
{
    TNODE * p = nullptr;
    printf("Root:  %c\n", root->c);
    printf("Children:  ");
    p = root->pchild;
    while(p != nullptr) {
        printf("%c", p->c);
        p = p->psibling;
    }

}
void FreeTree(TNODE * &pr) {
    if(pr == nullptr)
        return;
    FreeTree(pr->psibling);
    FreeTree(pr->pchild);
    free(pr);
}
void DestoryTree(TNODE * &root){
    FreeTree(root);
    root = nullptr;
}

int main() {
    char s[100];
    scanf("%s", s);
    TNODE *root;
    root = (TNODE *)malloc(sizeof(TNODE));
    GenTree(root, s);
    PrintTree(root);
    DestoryTree(root);
    return 0;
}