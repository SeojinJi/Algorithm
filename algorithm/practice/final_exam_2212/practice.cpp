#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_NUM 100000

using namespace std;

typedef pair<int, int> Pair;

class Heap{
    private :
        vector<pair<int, int>> Arr;
    public:
        Heap();
        ~Heap();
        void push(int e, int v);
        int top();
        int topvalue();
        void pop();
        bool empty(){return Arr.empty();}
        void Build_Heap();
        void Heapify(int index);
        int indexOf(int v);
        void fixKey(int key, int v);
        void make_empty();
};

Heap::Heap() {}
Heap::~Heap() {}
void Heap::push(int e, int v){
    Arr.push_back(make_pair(e,v));
    Built_Heap();
}

int Heap::top(){
    return Arr[0].second;
}

int Heap::topvalue(){
    return Arr[0].first;
}

void Heap::pop(){
    swap(Arr[Arr.size()-1], Arr[0]);
    Arr.pop_back();
    Heapify(0);
}

void Heap::Build_Heap(){
    for(int i = (Arr.size()/2) - 1; i >= 0; i--){
        Heapify(i);
    }
}

void Heap::Heapify(int index){
    int l = (index + 1) * 2 - 1;
    int r = (index + 1) * 2;
    int tmp = index;
    if((Arr.size()>l) && Arr[l] < Arr[tmp]){
        tmp = l;
    }
    if((Arr.size()> r) && Arr[r] < Arr[tmp]){
        tmp = r;
    }
    if(tmp != index){
        swap(Arr[index], Arr[tmp]);
        Heapify(tmp);
    }
}

int Heap::indexOf(int v){
    for(int i = 0; i < Arr.size(); i++){
        if(Arr[i].second == v){
            return i;
        }
    }
    return -1;
}

void Heap::fixKey(int key, int v){
    int i = indexOf(v);
    Arr[i].first = key;
    while(i > 0 && (Arr[i] < Arr[(i-1)/2])){
        swap(Arr[i], Arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void Heap::make_empty(){
    while(!Arr.empty()){
        Arr.pop_back();
    }
}

class Graph{
    private:
        Heap Q;
        int V;
        int *parent;
        vector<Pair> *adj;
        vector<Pair<int, Pair>> Edge;

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
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    Edge.push_back(make_pair(w, make_pair(u,v)));
}

void Graph::prim(){
    Q.make_empty();
    for(int i = 0; i < V; i++){
        Q.push(MAX_NUM, i);
    }
    int root = 0;
    vector<int> key(V, MAX_NUM);
    vector<bool> check(V, false);
    vector<int> mst(V, -1);
    key[root] = 0;
    Q.fixKey(0, root);
    while(!Q.empty()){
        int u = Q.top();
        Q.pop();
        check[u] = true;
        vector<Pair>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++){
            int v = (*i).first;
            int vw = (*i).second;
            if(!check[v] && key[v] > vw){
                key[v] = vw;
                mst[v] = u;
                Q.fixKey(key[v], v);
            }
        }
    }
}

int Graph::find_set(int i){
    if(i == parent[i]) return i;
    else return find_set(parent[i]);
}

int Graph::union_set(int u, int v){
    int parentu = find_set(u);
    int parentv = find_set(v);
    parent[parentu] = parent[parentv];
}

void Graph::kruskal(){
    int i, u, v;
    vector<pair<int, int>> mst;
    sort(Edge.begin(), Edge.end());
    for(i = 0; i < Edge.size(); i++){
        u = Edge[i].second.first;
        v = Edge[i].second.second;
        if(find_set(u) != find_set(v)){
            mst.push_back(make_pair(u,v));
            union_set(u,v);
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
}

void Graph::dijkstra(int src){
    Q.make_empty();
    for(int i = 0; i < V; i++){
        Q.push(MAX_NUM, i);
    }
}