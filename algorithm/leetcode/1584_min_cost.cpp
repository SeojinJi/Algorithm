#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct DisjointSet{
        vector<int> parent, rank;
        DisjointSet(int n) : parent(n), rank(n,1){
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int find(int u){
            if(parent[u] == u){
                return u;
            }
            return parent[u] = find(parent[u]);
        }
        void merge(int u, int v){
            int uparent = find(u);
            int vparent = find(v);
            if(uparent == vparent){
                return;
            }
            if(rank[uparent] > rank[vparent]){
                parent[uparent] = vparent; 
            }
            else if(rank[vparent] > rank[uparent]){
                parent[vparent] = uparent;
            }
            else{
                parent[uparent] = vparent;
                rank[vparent] += 1;
            }
        }
    };

    vector<pair<int, pair<int,int>>> allGraph(vector<vector<int>>& points){
        vector<pair<int, pair<int,int>>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j <points.size(); j++){
                if (i==j){
                    continue;
                }
                int number = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({number, {i, j}});
            }
        }
        return edges;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int,int>>> edges = Solution::allGraph(points);
        sort(edges.begin(), edges.end());
        
        DisjointSet sets(points.size());

        int output = 0;
        int i = 0;
        int number = 0;
        while(number < points.size()-1){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int weight = edges[i].first;
            if(sets.find(u) != sets.find(v)){
                sets.merge(u,v);
                output += weight;
                number += 1;
            }
            i++;
        }
        return output;
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    Solution solution;
    int result = solution.minCostConnectPoints(points);

    cout << result << endl;
    return 0;
}