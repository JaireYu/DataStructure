#include <iostream>
typedef struct BTNODE{
    int x;
    BTNODE * left;
    BTNODE * right;
}BTNODE;

void Insert(int node, BTNODE * &root){
    BTNODE *p, *pa;
    p = root; pa = nullptr;
    while(p != nullptr){
        if(node < p->x){
            pa = p;
            p = p->left;
        }
        else{
            pa = p;
            p = p -> right;
        }
    }
    if(node < pa->x){
        BTNODE *pnode = (BTNODE *)malloc(sizeof(BTNODE));
        pnode -> x = node;
        pa -> left = pnode;
        pnode -> left = pnode -> right = nullptr;
    }
    else{
        BTNODE *pnode = (BTNODE *)malloc(sizeof(BTNODE));
        pnode -> x = node;
        pa -> right = pnode;
        pnode -> left = pnode -> right = nullptr;
    }
}

void CreateTree(const int s[10], BTNODE * &root){
    int i = 0;
    while(i < 10){
        Insert(s[i], root);
        i++;
    }
}

void DeleteNode(int key, BTNODE * root){
    BTNODE * p, *pa, *t, *s;
    int flag;
    p = root;pa =nullptr;
    while(p != nullptr){
        if(key < p->x){
            pa = p;
            p = p->left;
            flag = 0;
        }
        else if(key > p->x){
            pa = p;
            p = p -> right;
            flag = 1;
        }
        else
            break;
    }
    if(p->left == nullptr&&p->right == nullptr){
        if(flag == 0)
            pa->left = nullptr;
        if(flag == 1)
            pa->right = nullptr;
        delete p;
        return;
    }
    if(p->right == nullptr){
        pa->left = p->left;
        delete p;
        return;
    }
    if(p->left == nullptr){
        pa->right = p->right;
        delete p;
        return;
    }
    pa = p;
    t = p->right;
    while(t->left != nullptr){
        pa = t;
        t = t->left;
    }
    p->x = t->x;
    if(pa != p)
        pa->left = t->right;
    else
        pa->right = t->right;
    delete t;
}

void PrintTree(BTNODE * root){
    if(root == nullptr)
        return;
    printf("%d*",root->x);
    PrintTree(root->left);
    PrintTree(root->right);
}
int main() {
    BTNODE * root = (BTNODE *)malloc(sizeof(BTNODE));
    root -> x = 11;
    root -> left = nullptr;
    root -> right = nullptr;
    int s[10] = {5,2,9,1,23,3,33,6,46,10};
    CreateTree(s, root);
    DeleteNode(9, root);
    PrintTree(root);
    return 0;
}