#include <vector>
#include <iostream>
#include <algorithm>
#include "05_heaps.h"
#define MAX_NUM 100000

using namespace std;

typedef pair<int, int> Pair;

class Graph{
    private:
        Heap Q;
        int V;
        int *parent;
        vector<Pair> *adj;
        vector<pair<int, Pair>> Edge;

    public:
        Graph();
        Graph(int V);
        ~Graph();
        void addEdge(int u, int v, int w);
        void prim();
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal();
        void dijkstra(int src);
        void bellman_ford(int src);
};

Graph::Graph(){}

Graph::Graph(int V) : V(V){
    adj = new vector<Pair>[V];
    parent = new int[V];
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }
}

Graph::~Graph(){}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
    Edge.push_back(make_pair(w, make_pair(u,v)));
    // Edge.push_back(make_pair(w, make_pair(v,u))); 
}

int Graph::find_set(int i){
    if(i == parent[i]){
        return i;
    }
    else{
        return find_set(parent[i]);
    }
}

void Graph::union_set(int u, int v){
    int parentu = find_set(u);
    int parentv = find_set(v);
    parent[parentu] = parent[parentv];
}

void Graph::kruskal(){
    int i, u, v;
    vector<pair<int, int>> mst; // MST Edge container <vertex, vertex>
    sort(Edge.begin(), Edge.end());
    for(i = 0; i < Edge.size(); i++){
        u = Edge[i].second.first;
        v = Edge[i].second.second;
        if(find_set(u) != find_set(v)){
            mst.push_back(make_pair(u,v));
            union_set(u, v);
        }
    }
    printf("Selected Edge for MST \n");
    for(int i = 0; i < mst.size(); i++){
        printf("%d - %d\n", mst[i].first, mst[i].second);
    }
}

void Graph::prim(){
    Q.make_empty();
    for(int i = 0; i < V; i++){
        Q.push(MAX_NUM, i);
    }
    int root = 0;
    vector<int> key(V, MAX_NUM); // minWeight 보관
    vector<bool> check(V, false);
    vector<int> mst(V, -1);
    key[root] = 0;
    Q.fixKey(0, root);
    while(!Q.empty()){
        int u = Q.top();
        Q.pop();
        check[u] = true;
        vector<Pair>::iterator i;
        for(i = adj[u].begin(); i!= adj[u].end(); i++){
            int v = (*i).first;
            int weight = (*i).second;
            if(!check[v] && key[v] > weight){
                key[v] = weight;
                mst[v] = u;
                Q.fixKey(weight, v);
            }
        }
    }
}

void Graph::bellman_ford(int src){
    int u, v;
    vector<int> dist(V, MAX_NUM);
    dist[src] = 0;
    for(int i = 0; i < V-1; i++){
        for(int j = 0; j < Edge.size(); j++){
            u = Edge[j].second.first;
            v = Edge[j].second.second;
            if(dist[v] > dist[u] + Edge[j].first){
                dist[v] = dist[u] + Edge[j].first;
            }
        }
    }
    for(int k = 0; k < Edge.size(); k++){
        u = Edge[k].second.first;
        v = Edge[k].second.second;
        if(dist[v] > dist[u] + Edge[k].first){
            printf("Graph contains negative!\n");
            return;
        }
    }

    printf("Vectex Distance from Source\n");
    for(int i = 0; i < V; i++){
        printf("%d \t \t %d\n", i, dist[i]);
    }
}

void Graph::dijkstra(int src){
    Q.make_empty();
    for(int i = 0; i < V; i++){
        Q.push(MAX_NUM, i);
    }
    vector<int> dist(V, MAX_NUM);
    dist[src] = 0;
    Q.fixKey(0, src);
    while(!Q.empty()){
        int now = Q.top(); // 현재 노드
        int weight = Q.topvalue(); // 현재 노드의 weight
        Q.pop();
        vector<Pair>::iterator i;
        // if(dist[now] < weight) continue; // 이미 최단 경로를 체크한 노드인 경우 패스
        for(i = adj[now].begin(); i != adj[now].end(); i++){
            int v = (*i).first;
            int vw = (*i).second;
            if(dist[v] > dist[now] + vw){
                dist[v] = dist[now] + vw;
                Q.fixKey(dist[v], v);
            }
        }
    }
    printf("Vectex Distance from Source\n");
    for(int i = 0; i < V; i++){
        printf("%d \t \t %d\n", i, dist[i]);
    }
}

int main(){
    int V = 6;
    Graph g(V);

    g.addEdge(0,1,1);
    g.addEdge(0,2,2);
    g.addEdge(0,4,6);
    g.addEdge(1,2,8);
    g.addEdge(2,4,3);
    g.addEdge(3,2,7);
    g.addEdge(3,2,7);
    g.addEdge(3,1,5);
    g.addEdge(4,3,4);

    g.bellman_ford(0);
    cout << endl;
    g.dijkstra(0);

    return 0;
}