//Prim算法
//测试例子
//书P238 7.16(a)
//6 10
//A 0 7 4 3 0 7
//B 7 0 0 6 5 2
//C 4 0 0 8 5 0
//D 3 6 8 5 1 0
//E 0 5 5 1 0 0
//F 7 2 0 0 0 0
#include <iostream>
#define n 6
using namespace std;

typedef struct {
    int Vnum, Enum;
    int adjoin[n][n];//邻接矩阵
    char V[n];//节点元素
}Graph;

typedef struct {
    int Weight;
    int V1;
    int V2;
}Prim;

void InitGraph(Graph &G, int &temp) {
    int i, j;
    temp = 0;
    cout << "input Vnum and Enum" <<endl;
    cin >> G.Vnum;
    cin >> G.Enum;
    cout << "input the state" <<endl;
    for (i = 0; i < n; i ++) {
        cin >> G.V[i];
        for (j = 0; j < n; j ++) {
              cin >> G.adjoin[i][j];
              if(G.adjoin[i][j] > temp)
                  temp = G.adjoin[i][j];
        }
    }
}

void SortOneE(Prim *&Tree, int *&visited, Graph G, int i, int temp) {
    int j, k, jtemp,ktemp;
    for(j = 0; j < n; j ++) {
        if(visited[j] == 1) {
            for(k = 0; k < n; k ++) {
                if(visited[k] == 0) {
                    if(G.adjoin[j][k] < temp && G.adjoin[j][k] != 0) {
                        temp = G.adjoin[j][k];
                        jtemp = j;
                        ktemp = k;
                    }
                }
            }
        }
    }
    visited[ktemp] = 1;
    Tree[i].V1 = jtemp;
    Tree[i].V2 = ktemp;
    Tree[i].Weight = G.adjoin[jtemp][ktemp];
}

void Print(Prim *Tree, Graph G) {
    Graph G0;
    int i, j;
    for(i = 0; i < n; i ++) {
        for(j = 0; j < n; j ++) {
            G0.adjoin[i][j] = 0;
        }
    }
    for(i = 0; i < n - 1; i ++) {
        G0.adjoin[Tree[i].V1][Tree[i].V2] = G0.adjoin[Tree[i].V2][Tree[i].V1] = Tree[i].Weight;
    }
    printf("The graph is:\n");
    for(i = 0; i < n; i ++) {
        printf("%c", G.V[i]);
        for(j = 0; j < n; j ++) {
            printf(" %d", G0.adjoin[i][j]);
        }
        printf("\n");
    }
    printf("The E of the prim tree:\n");
    for(i = 0; i < n - 1; i ++) {
        printf("%c-%c weight is %d\n", G.V[Tree[i].V1], G.V[Tree[i].V2], Tree[i].Weight);
    }
}


int main() {
    int i, temp;
    Graph G;
    Prim *Tree = (Prim *)malloc(sizeof(Prim) * (n - 1));
    int *visited = (int *)malloc(sizeof(int) * (n));
    for(i = 0; i < n ;i ++) {
        visited[i] = 0;
    }
    InitGraph(G, temp);
    visited[0] = 1;
    for(i = 0; i < n - 1; i ++) {
        SortOneE(Tree, visited, G, i, temp);
    }
    Print(Tree, G);
    delete(Tree);
    free(visited);
    return 0;
}