#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#define MAX 101

using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX];
int t, vertex, edge;
int NIL = numeric_limits<int>::min();
stack<int> st;

void DFS(vector<int>[]);
void DFS_VISIT(vector<int>[], int);
void TOPOLOGICAL_SORT(vector<int>[]);

void DFS(vector<int> G[]){
    for(int u = 0; u <= vertex; ++u){
        color[u] = WHITE;
        p[u] = NIL;
    }
    t = 0;
    for(int u = 1; u<=vertex; ++u){
        if(color[u] == WHITE){
            DFS_VISIT(G,u);
        }
    }
}

void DFS_VISIT(vector<int> G[], int u){
    t = t+1;
    d[u] = t; 
    color[u] = GRAY; // while vertex u has just been discovered
    for(int v = 0; v < G[u].size(); ++v){ // explore each edge (u, v)
        if(color[G[u][v]] == WHITE){
            p[G[u][v]] = u;
            DFS_VISIT(G, G[u][v]);
        }
    }
    t = t+1; 
    f[u] = t;
    color[u] = BLACK; // blakcen u; it is finished
    st.push(u); // The faster the finish time, the more inside it is stored in the stack
}

void TOPOLOGICAL_SORT(vector<int> G[]) {
    DFS(G);
    while(!st.empty()){
        int a = st.top(); 
        cout << a << endl; // Pop from the node with a later finish time.
        st.pop();
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    vector<int> adjList[MAX];

    int u, v;
    cin >> vertex >> edge;
    for(int e = 0; e < edge; ++e){
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    TOPOLOGICAL_SORT(adjList);
    return 0;
}
