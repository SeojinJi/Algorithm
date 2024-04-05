#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

int v, e;
vector<pair<int, int>> edges[MAX];

int prim(){
    int result = 0;
    vector<int> visited[v] = {0};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, 1)); // weight = 0, start point = 1; (start point priority = 0)

    while(!pq.empty()){
        int x = pq.top().second; // extract min
        int weightx = pq.top().first;
        pq.pop();
        if(visited[x] == 1) continue; // already visit
        result += weightx;
        visited[x] = 1; // visit
        for(int i = 0; i < edges[x].size(); i++){ 
            int u = edges[x][i].first;
            int weightu = edges[x][i].second;
            pq.push(make_pair(weightu, u));
        }
    }
    return result;
}

int main() {
    edges[0].push_back(make_pair(1, 4));
    edges[1].push_back(make_pair(0, 4));

    edges[0].push_back(make_pair(7, 8));
    edges[7].push_back(make_pair(0, 8));

    edges[1].push_back(make_pair(2, 8));
    edges[2].push_back(make_pair(1, 8));

    edges[1].push_back(make_pair(7, 11));
    edges[7].push_back(make_pair(1, 11));
 
    edges[2].push_back(make_pair(3, 7));
    edges[3].push_back(make_pair(2, 7));

    edges[2].push_back(make_pair(5, 4));
    edges[5].push_back(make_pair(2, 4));

    edges[2].push_back(make_pair(8, 2));
    edges[8].push_back(make_pair(2, 2));

    edges[3].push_back(make_pair(4, 9));
    edges[4].push_back(make_pair(3, 9));

    edges[3].push_back(make_pair(5, 14));
    edges[5].push_back(make_pair(3, 14));
 
    edges[4].push_back(make_pair(5, 10));
    edges[5].push_back(make_pair(4, 10));
 
    edges[5].push_back(make_pair(6, 2));
    edges[6].push_back(make_pair(5, 2));
    
    edges[6].push_back(make_pair(8, 6));
    edges[8].push_back(make_pair(6, 6));

    edges[6].push_back(make_pair(7, 1));
    edges[7].push_back(make_pair(6, 1));

    edges[7].push_back(make_pair(8, 7));
    edges[8].push_back(make_pair(7, 7));

    int mst=prim();

    cout << mst << endl;

    return 0;
}
