//判断是否联通图
//算法：深度优先遍历(递归)
#include <iostream>
#define n 4
using namespace std;
typedef struct {
    char V[n];
    int Vnum, Enum;
    int Adjoin[n][n];
}Graph;

int visited[n];

void InitGraph(Graph &G){
    int i,j;
    cin>>G.Vnum>>G.Enum;
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            cin>>G.Adjoin[i][j];
        }
    }
}
void DFS(Graph G, int visited[n], int V){
    int i;
    visited[V - 1] = 1;
    for(i = 0; i < n; i ++){
        if(G.Adjoin[V - 1][i] == 1 && visited[i] == 0){
            DFS(G, visited, i + 1);
        }
    }
}

void InitVisited(int visited[n]){
    int i;
    for(i = 0; i < n; i ++){
        visited[i] = 0;
    }
}

bool Check(int visited[n]){
    int i;
    for(i = 0; i < n; i ++){
        if(visited[i] == 0){
            return false;
        }
    }
}

int main() {
    int i;
    Graph G;
    InitGraph(G);
    for(i = 0; i < n; i ++){
        InitVisited(visited);
        DFS(G, visited, i+1);
        if(Check(visited) == false){
            cout<<"unconnected"<<endl;
            return 0;
        }
    }
    cout<<"connected"<<endl;
    return 0;
}