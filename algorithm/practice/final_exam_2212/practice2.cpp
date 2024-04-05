#include <iostream>
#include <vector>
#include <limits>
#include <list>
#define MAX 101

using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX];
int t, vertex, edge;
int NIL = numeric_limits<int>::min();

void BFS(vector<int> G[], int source){
    for(int i = 0; i < vertex; i++){
        color[i] = WHITE;
        d[i] = 100000;
        p[i] = NIL;
    }
    color[source] = GRAY;
    d[source] = 0;
    list<int> Q;
    Q.push_back(source);
    while(!Q.empty()){
        int a = Q.front();
        Q.pop_front();
        for(int i = 0; i < G[a].size(); i++){
            if(color[G[a][i]] == WHITE){
                color[G[a][i]] = GRAY;
                d[G[a][i]] = d[a] + 1;
                p[G[a][i]] = a;
                Q.push_back(G[a][i]);
            }
        }
        color[a] = BLACK;
    }
}

void DFS(vector<int> G[]){
    for(int u = 0; u < vertex; ++u){
        color[u] = WHITE;
        d[u] = 100000;
        f[u] = 100000;
        p[u] = NIL;
    }
    int t = 0;
    for(int i = 0; i < vertex; i++){
        if(color[i] == WHITE){
            DFS_VISIT(G, i);
        }
    }
}

void DFS_VISIT(vector<int> G[], int u){
    t += 1;
    d[u] = t;
    color[u] = GRAY;
    for(int i = 0; i < G[u].size(); i++){
        if(color[G[u][i]] == WHITE){
            p[G[u][i]] = u;
            DFS_VISIT(G, G[u][i]);
        }
    }
    t += 1;
    f[u] = t;
    color[u] = BLACK;
    st.push(u);
}