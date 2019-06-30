//求关键路径
//算法
//1.对节点拓扑排序
//2.按定义求出ve，vl；
//测试例子：（书图7.21）
//9 11 （vnum,enum）
//1 0 6 4 5 0 0 0 0 0
//2 0 0 0 0 1 0 0 0 0
//3 0 0 0 0 1 0 0 0 0
//4 0 0 0 0 0 2 0 0 0
//5 0 0 0 0 0 0 9 7 0
//6 0 0 0 0 0 0 0 4 0
//7 0 0 0 0 0 0 0 0 2
//8 0 0 0 0 0 0 0 0 4
//9 0 0 0 0 0 0 0 0 0
#include <iostream>
#define n 9
using namespace std;
typedef struct {
    char V;//节点字符
    int index;//下标
    int ve;//最早开始时间
    int vl;//最迟开始时间
}TriV;

typedef struct {
    char v[n];
    int Vnum, Enum;
    int adjoin[n][n];
    TriV V[n];//拓扑排序表
}Graph;

void InitGraph(Graph &G) {
    int i, j;
    cout<<"input Vnum & Enum"<<endl;
    cin>>G.Vnum;
    cin>>G.Enum;
    cout<<"input out state"<<endl;
    for(i = 0; i < n; i ++){
        //cout<<"input out state"<<endl;
        cin>>G.v[i];
        for(j = 0; j < n; j ++){
            cin>>G.adjoin[i][j];
        }
    }

}

bool GetInZeroV(Graph &G, int j) {
    int i;
    for(i = 0; i < n; i ++){
        if(G.adjoin[i][j] != 0)
            return false;
    }
    return true;
}

void Copy(Graph G, Graph &G0) {
    int i, j;
    for(i = 0; i < n; i ++){
        G0.v[i] = '\0';
    }
    for(i = 0; i < n; i ++){
        G0.v[i] = G.v[i];
        for(j = 0; j < n; j ++){
            G0.adjoin[i][j] = G.adjoin[i][j];
        }
    }
    G0.Enum = G.Enum;
    G0.Vnum = G.Vnum;
}

void DeleteGraph(Graph &G, int i, int *&visited) {
    int j, k;
    for(j = 0; j < n; j ++) {
        if(visited[j] == i) {
            for(k = 0; k < n; k ++) {
                G.adjoin[j][k] = 0;
            }
        }
    }
}

void SortGraph(Graph &G, int &n0, int &i, int visited[]){
    if(n0 == 0)
        return;
    int j;
    for(j = 0; j < n; j ++){
        if(GetInZeroV(G, j) == true && visited[j] == 0) {
            G.V[n - n0].V = G.v[j];
            G.V[n - n0].index = j;
            n0 --;
            visited[j] = i;
        }
    }
    DeleteGraph(G, i, visited);
    i ++;
    SortGraph(G, n0, i, visited);
}

void print(Graph G0) {
    int i;
    for(i = 0; i < n; i ++) {
        printf("%c\t%d\t%d\n", G0.V[i].V, G0.V[i].ve, G0.V[i].vl);
    }
}

void CulculateVe(Graph G, Graph &G0) {
    int i,j,k;
    G0.V[0].ve = 0;
    for(i = 1; i < n; i ++) {
        k = 0;
        for(j = 0; j < i; j ++) {
            if(G.adjoin[j][G0.V[i].index] != 0 && k == 0) {
                G0.V[i].ve = G0.V[j].ve + G.adjoin[j][G0.V[i].index];
                k = 1;
            }
            if(G.adjoin[j][G0.V[i].index] != 0 && k == 1) {
                if((G0.V[j].ve + G.adjoin[j][G0.V[i].index]) > G0.V[i].ve)
                    G0.V[i].ve = G0.V[j].ve + G.adjoin[j][G0.V[i].index];
            }
        }
    }
}

void CulculateVl(Graph G, Graph &G0) {
    int i, j, k;
    G0.V[n-1].vl = G0.V[n-1].ve;
    for(i = n-1; i >= 0; i --) {
        k = 0;
        for(j = i; j < n; j ++) {
            if(G.adjoin[G0.V[i].index][j] != 0 && k == 0) {
                G0.V[i].vl = G0.V[j].vl - G.adjoin[G0.V[i].index][j];
                k = 1;
            }
            if(G.adjoin[G0.V[i].index][j] != 0 && k == 1) {
                if((G0.V[j].vl + G.adjoin[G0.V[i].index][j]) < G0.V[i].vl)
                    G0.V[i].vl = G0.V[j].vl + G.adjoin[G0.V[i].index][j];
            }
        }
    }

}
int main() {
    int visited[n] = {0}, i = 1;
    int n0 = n;
    Graph G, G0;
    InitGraph(G);
    Copy(G, G0);
    SortGraph(G0, n0, i,visited);//G--adjoin, G0--V[n]
    CulculateVe(G, G0);
    CulculateVl(G, G0);
    printf("v\tve\tvl\n");
    print(G0);
    printf("the key path node is");
    for(i = 0; i < n; i ++) {
        if(G0.V[i].ve == G0.V[i].vl)
            printf(" %c",G0.V[i].V);
    }
    return 0;
}