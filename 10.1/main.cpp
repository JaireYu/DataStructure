//二叉树找公共祖先
#include <iostream>
typedef struct {
    int top;
    char S[100];
}Stake;
typedef struct BTree{
    char c;
    BTree * lchild;
    BTree * rchild;
}BTree;
void SearchPATH(Stake &S, char ch,BTree *root, int &flag);
char Compare(Stake S1, Stake S2);
void CreateBTree(const char *s, BTree * root);
void Search(char ch, BTree * root, BTree * &p);
void InitStake(Stake &S){
    S.top = 0;
}
void PushS(Stake &S, char ch){
    S.S[S.top] = ch;
    S.top ++;
}
void PopS(Stake &S){
    S.top --;
}
int main() {
    char ch1, ch2;
    scanf("%c %c",&ch1, &ch2);
    Stake S1,S2;
    InitStake(S1);
    InitStake(S2);
    BTree * root;
    root = (BTree *)malloc(sizeof(BTree));
    const char *s="A;A,B,C;B,D,E;C,*,I;D,G,H;E,F,*;#";
    CreateBTree(s, root);
    int flag = 0;
    SearchPATH(S1, ch1, root, flag);
    flag = 0;
    SearchPATH(S2, ch2, root, flag);
    PopS(S1);PopS(S2);
    printf("%c", Compare(S1, S2));
    return 0;
}
void Search(char ch, BTree * root, BTree * &p){
    if(root == nullptr)
        return;
    if(root->c == ch){
        p = root;return;
    }
    Search(ch, root->lchild, p);
    Search(ch, root->rchild, p);
}
void CreateBTree(const char *s, BTree * root){
    int i = 0;
    BTree * p;
    root->c = s[0];
    root->lchild = nullptr;
    root->rchild = nullptr;
    i += 2;
    while(s[i] != '#'){
        p = nullptr;
        Search(s[i], root, p);
        if(s[i+2] == '*')
            p->lchild = nullptr;
        else{
            p->lchild = (BTree *)malloc(sizeof(BTree));
            p->lchild->c = s[i+2];
            p->lchild->lchild = p->lchild->rchild = nullptr;
        }
        if(s[i+4] == '*')
            p->rchild = nullptr;
        else{
            p->rchild = (BTree *)malloc(sizeof(BTree));
            p->rchild->c = s[i+4];
            p->rchild->lchild = p->rchild->rchild = nullptr;
        }
        i += 6;
    }
}
void SearchPATH(Stake &S, char ch,BTree *root, int &flag){
    if(root == nullptr)
        return;
    if(flag == 1)
        return;
    PushS(S, root->c);
    if(root->c == ch)
        flag = 1;
    SearchPATH(S, ch, root->lchild, flag);
    if(flag == 1)
        return;
    SearchPATH(S, ch, root->rchild, flag);
    if(flag == 1)
        return;
    PopS(S);
}

char Compare(Stake S1, Stake S2){
    int i = 0;
    while(i<S1.top&&i<S2.top){
        if(S1.S[i] != S2.S[i]){
            if(i > 0)
                return S1.S[i-1];
        }
        i++;
    }
    if(i == 0){
        printf("No Ancestry!");
        return ' ';
    }
    if(i == S1.top)
        return S1.S[S1.top-1];
    if(i == S2.top)
        return S2.S[S2.top-1];
}