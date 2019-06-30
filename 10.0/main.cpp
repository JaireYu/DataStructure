//找双亲结点（注意每一个节点的孩子是否存在不知道时引用->会造成错误）
#include <iostream>
typedef struct BTree{
    char c;
    BTree * lchild;
    BTree * rchild;
}BTree;
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
void GetNodeParent(char ch, BTree * root, BTree * &parent){
    if(root == nullptr)
        return;
    if(root->lchild != nullptr && root->rchild != nullptr){
        if(root->lchild->c == ch){
            parent = root;
            return;
        }
        if(root->rchild->c == ch){
            parent = root;
            return;
        }
    }
    else if(root->lchild == nullptr && root->rchild != nullptr){
        if(root->rchild->c == ch){
            parent = root;
            return;
        }
    }
    else if(root->lchild != nullptr && root->rchild == nullptr){
        if(root->lchild->c == ch){
            parent = root;
            return;
        }
    }
    else{
        return;
    }
    GetNodeParent(ch, root->lchild, parent);
    GetNodeParent(ch, root->rchild, parent);
}
int main() {
    char ch;
    scanf("%c", &ch);
    const char *s="A;A,B,C;B,D,E;C,*,I;D,G,H;E,F,*;#";
    BTree * parent = nullptr;
    BTree * root;
    root = (BTree *)malloc(sizeof(BTree));
    CreateBTree(s, root);
    GetNodeParent(ch, root, parent);
    if(parent != nullptr)
        printf("%c", parent->c);
    else
        printf("No found\n");
    return 0;
}