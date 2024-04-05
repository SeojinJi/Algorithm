#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAX 10000

using namespace std;

int vertex, edge, start;
vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    d[start] = 0; // initialize-single-source

    while(!pq.empty()){
        int dist = pq.top().first; // 현재 노드 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        if(d[now] < dist){ // 이미 최단경로를 체크한 노드인 경우 패스
            continue;
        }
        for(int i = 0; i < graph[now].size(); i++){
            int cost = dist+graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(cost, graph[now][i].first));
            }
        }
    }
}

int main(void){
    cin >> vertex >> edge >> start;

    for(int i = 0; i < edge; i++){
        int a, b, c;
        graph[a].push_back(make_pair(b,c));
    }

    fill(d, d+MAX, INF); // 최단거리 테이블 d를 모두 INF로 초기화

    dijkstra(start);

    for(int i = 1; i <= vertex; i++){
        if(d[i] == INF){
            cout << "CAN NOT REACH" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }

    return 0;
}