#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9
#define MAX 501

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
long long d[MAX];

bool bellmanFord(int start){
    d[start] = 0;

    for(int i = 1; i <= n; i++){ // n : node 개수 (지날 수 있는 최대 edges 개수는 n-1)
        for(int j = 0; j < m ; j++){ // 모든 edge를 한 번씩 확인한다
            int from = edges[j].first;
            int to = edges[j].second.first;
            int cost = edges[j].second.second;

            if(d[from] == INF) continue; // 한 번이라도 계산된 정점에 대해서만

            if(d[to] > d[from] + cost){ // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                d[to] = d[from] + cost; // 최단 거리 테이블 갱신
            
                if (i == n) return false; // n번째에도 최단 거리가 갱신된다면, 음수 사이클이 존재한다고 판단
                                          // negative weight이 없으면 해당 코드 필요 없음
            }

        } 
    }

    return true;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, {b,c}});
    }

    fill_n(d, MAX, INF);

    bool negativeCycle = bellmanFord(1);

    if(!negativeCycle){
        cout << "can not compute it!";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        cout << d[i] << endl;
    }

    return 0;
}