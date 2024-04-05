#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_V = 100;
const int INF = 987654321;

int V = 9;

struct DisjointSet{
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    int find(int u){
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return ;
        if(rank[u]> rank[v]){
            parent[u] = v;
        }
        else if(rank[u] < rank[v]){
            parent[v] = u;
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
};

int kruskal(vector<pair<int, pair<int, int>>> &edges, vector<pair<int, int>> &selected){
    selected.clear();

    sort(edges.begin(), edges.end()); // sort the list of edges into monotonically increasing order by weight w
    
    DisjointSet sets(V);

    int ret = 0;

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;

        if(sets.find(u)!= sets.find(v)){ // acycle
            sets.merge(u,v); // union(u, v)
            selected.push_back(make_pair(u,v));
            ret += weight;
        }
    }

    return ret;
}

int main() {
    vector<pair<int, int>> selected;
    vector<pair<int, pair<int,int>>> edges;

    edges.push_back({4, {0,1}});
    edges.push_back({8, {0,7}});
    edges.push_back({8, {1,2}});
    edges.push_back({11, {1,7}});
    edges.push_back({7, {2,3}});
    edges.push_back({4, {2,5}});
    edges.push_back({2, {2,8}});
    edges.push_back({9, {3,4}});
    edges.push_back({14, {3,5}});
    edges.push_back({10, {4,5}});
    edges.push_back({2, {5,6}});
    edges.push_back({6, {6,8}});
    edges.push_back({1, {6,7}});
    edges.push_back({7, {7,8}});

    int totalWeight=kruskal(edges, selected);

    cout << "Total Weight of Minimum Spanning Tree (Kruskal): " << totalWeight << endl;

    cout << "Selected Edges:" << endl;
    for (const auto& edge : selected) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}

