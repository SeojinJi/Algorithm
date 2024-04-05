#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** allGraph(int** points, int pointsSize){
    // edges 배열 할당
    int row = pointsSize * (pointsSize - 1);
    int** edges = (int **) malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        edges[i] = (int *) malloc (3 * sizeof(int));
    }
    int index = 0;
    for(int i = 0; i < pointsSize; i++){
        for(int j = 0; j < pointsSize; j++){
            if(i==j){
                continue;
            }
            int number = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[index][0] = number;
            edges[index][1] = i;
            edges[index][2] = j;
            index++;
        }
    }
    return edges;
}

int find(int u, int* parent){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = find(parent[u], parent);
}

void merge(int u, int v, int* rank, int* parent){
    int uparent = find(u, parent);
    int vparent = find(v, parent);
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

int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int** edges = allGraph(points, pointsSize);
    int row = pointsSize * (pointsSize - 1);
    qsort(edges, row, sizeof(int), compare);
    int* parent = (int *)malloc(pointsSize * sizeof(int));
    int* rank = (int *)malloc(pointsSize * sizeof(int));
    for(int i = 0; i < pointsSize; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    int number = 0;
    int index = 0;
    int result = 0;
    while(number < pointsSize - 1){
        int weight = edges[index][0];
        int u = edges[index][1];
        int v = edges[index][2];
        int x = find(u, parent);
        int y = find(v, parent);
        if(x != y){
            number += 1;
            result += weight;
            merge(x, y, rank, parent);
        }
    }
    return result;
}

int main(){
    int* points[5][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int pointsSize = 5;
    int pointsColSize = 2;

    int result = minCostConnectPoints((int**)points, pointsSize, &pointsColSize);
    printf("%d", result);
    return 0;
}