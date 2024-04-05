#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#define MAX 101

using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX];
int l, t, vertex, edge;
int NIL = numeric_limits<int>::min();
stack<int> st;
vector<int> sccList(MAX);
int sccCnt = 0;

void STRONGLY_CONNECTED_COMPONENTS(vector<int>[], vector<int>[]);
void DFS(vector<int>[]);
void DFS_VISIT(vector<int>[], int);
void DFS_SCC_VISIT(vector<int>[], int);

void STRONGLY_CONNECTED_COMPONENTS(vector<int> G[], vector<int> G2[]) {
    DFS(G);
    for(int u = 0; u <= vertex; ++u) {
        color[u] = WHITE;
    }
    while(!st.empty()){
        int a = st.top();
        st.pop();
        if(color[a] == WHITE){
            DFS_SCC_VISIT(G2, a); // visit the vertices in order of decreasing finish time
            sccCnt++; // output the vertices of each tree in the dft as a separate strongly connected component
        }
    }
   
    for(int j = 0 ; j < sccCnt ; j++){
        cout << "scc List " << j << " : " ;
        for(int i = 1; i <= vertex; i++){
            if(j == sccList[i]){
                cout << i << " " ;
            }
        }
        cout << endl;
    }
}

void DFS(vector<int> G[]) {
    for(int u = 0; u <= vertex; ++u) { // initialize
        color[u] = WHITE;
        p[u] = NIL;
    }
    t = 0;
    for(int u = 1; u <= vertex; ++u) {
        if(color[u] == WHITE) {
            DFS_VISIT(G, u);
        }
    }
}

void DFS_VISIT(vector<int> G[], int u) {
    t += 1; // while vertex u has just been discovered
    d[u] = t;
    color[u] = GRAY;
    for(int v : G[u]) { // explore each edge (u, v)
        if(color[v] == WHITE) {
            p[v] = u;
            DFS_VISIT(G, v);
        }
    }
    t += 1;
    f[u] = t;
    color[u] = BLACK; // blakcen u; it is finished
    st.push(u); // The faster the finish time, the more inside it is stored in the stack
}

void DFS_SCC_VISIT(vector<int> G2[], int k) {
    sccList[k] = sccCnt;
    color[k] = GRAY;
    for(int v : G2[k]){
        if(color[v] == WHITE){
            DFS_SCC_VISIT(G2, v);
        }
    }
    color[k] = BLACK;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    vector<int> adjList[MAX];
    vector<int> adjListReverse[MAX];

    int u, v;
    cin >> vertex >> edge;
    for(int e = 0; e < edge; ++e) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListReverse[v].push_back(u); // generate reverse graph
    }
    STRONGLY_CONNECTED_COMPONENTS(adjList, adjListReverse);
    return 0;
}
