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

void STRONGLY_CONNECTED_COMPONENTS(vector<int>[], int);
void BFS(vector<int>[], int);

int main(void){
    freopen("input.txt", "r", stdin);
    vector<int> adjList[MAX];

    int u, v;
    cin >> vertex >> edge;
    for(int e = 0; e < edge; ++e){
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    
    STRONGLY_CONNECTED_COMPONENTS(adjList, 1);
    return 0;
}

void STRONGLY_CONNECTED_COMPONENTS(vector<int> G[], int v){
    BFS(G, v);
    for(int v = 1; v <= vertex; v++){
        printf("vectex%d : %d\n", v, d[v]);
    }
}

void BFS(vector<int> G[], int v){
    for(int u = 0; u <= vertex; ++u){ // initialize
        color[u] = WHITE;
        d[u] = 100000;
        p[u] = NIL;
    }
    color[v] = GRAY;
    d[v] = 0;
    p[v] = NIL;

    list<int> q;
    q.push_back(v); // insert start point 

    while(!q.empty()){
        int a = q.front();
        q.pop_front();
        for(int v = 0; v < G[a].size(); ++v){ // search the nieghbors of a
            if(color[G[a][v]] == WHITE){ // is G[a][v] being discovered now?
                color[G[a][v]] = GRAY;  // discover!
                d[G[a][v]] = d[a] + 1;
                p[G[a][v]] = a;
                q.push_back(G[a][v]); // G[a][v] is now on the frontier
            }
        }
        color[a] = BLACK; // a is now behind the frontier
    }
}


