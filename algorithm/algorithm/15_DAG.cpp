#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#define MAX 100

using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX];
int t, vertex, edge;
int NIL = numeric_limits<int>::min();
stack<int> st;
vector<pair<int, int>> edges[MAX];
vector<int> cost(vertex, INT_MAX);

void DFS(vector<pair<int, int>> edges[]);
void DFS_VISIT(vector<pair<int, int>> edges[], int);
void DAG(vector<pair<int, int>> edges[], int source);

void DFS(vector<pair<int, int>> edges[]){
    for(int u = 0; u <= vertex; ++u){
        color[u] = WHITE;
        p[u] = NIL;
    }
    t = 0;
    for(int u = 1; u<=vertex; ++u){
        if(color[u] == WHITE){
            DFS_VISIT(edges,u);
        }
    }
}

void DFS_VISIT(vector<pair<int, int>> edges[], int u){
    t = t+1;
    d[u] = t;
    color[u] = GRAY;
    for(int v = 0; v < edges[u].size(); ++v){
        if(color[edges[u][v].first] == WHITE){
            p[edges[u][v].first] = u;
            DFS_VISIT(edges, edges[u][v].first);
        }
    }
    color[u] = BLACK;
    t = t+1;
    f[u] = t;
    st.push(u);
}

void DAG(vector<pair<int, int>> edges[], int source) {
    cost[source] = 0;
    DFS(edges);
    while(!st.empty()){ // topological sort를 stack으로 구현
        int a = st.top(); // 가장 맨 마지막에 끝난 node부터 순서대로 pop
        st.pop();
        for(int i = 0; i < edges[a].size(); i++){
            int u = edges[a][i].first;
            int w = edges[a][i].second;

            if(cost[a] != INT_MAX && cost[a] + w < cost[u]){ // relax
                cost[u] = cost[a] + w;
            }
        }
    }

    for(int i = 0; i < vertex; i++){ // print shortest path
        cout << "dist(" << source << ", " << i << ")" << cost[i];
        cout << endl;
    }
}

int main(void){

    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b,c));
    }

    DAG(edges, 1);

    return 0;

}
