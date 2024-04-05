#include <iostream>
#include <array>
#include <limits>
#define INF 10000


using namespace std;

const int n = 5; 

array<array<int, n>,n> floyd_warshall_pred(array<array<int, n>,n> W){
    array<array<int, n>,n> D;
    array<array<int, n>,n> P;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            D[i][j] = W[i][j];
            P[i][j] = -1;
            if(i != j && W[i][j] != INF){
                P[i][j] = i;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }

    return D;
}