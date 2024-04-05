#include <iostream>
#include <array>
#define INF 10000

using namespace std;

const int n = 4; 

array<array<int, n>,n> extended_shortest_path(array<array<int, n>,n> L, array<array<int, n>,n> W){
    array<array<int, n>,n> N;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            N[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(N[i][j] > L[i][k] + W[k][j]){ // N[i][j] = min{N[i][j], L[i][k] + W[k][j]}
                    N[i][j] = L[i][k] + W[k][j];
                }
            }
        }
    }

    return N;

}

array<array<int, n>,n> slow_apsp(array<array<int, n>,n> W, array<array<int, n>,n> L0){
    array<array<int, n>, n> L = L0;

    for(int r = 1; r < n; r++){
        array<array<int, n>, n> M = extended_shortest_path(L, W); // initialize M, compute the matrix product M = L * W
        L = M; // recursive
    }

    return L;
}

array<array<int, n>,n> faster_apsp(array<array<int, n>,n> W){
    array<array<int, n>, n> L = W;
    int r = 1;
    while(r < n){
        array<array<int, n>, n> M = extended_shortest_path(L, L); // initialize M, compute M = L * L
        r = 2*r;
        L = M; // ready for the next iteration
    }

    return L;
}



int main(void){
    array<array<int, n>, n> W  = {{{0, 3, 8, INF},
                                {INF, 0, 4, 11},
                                {INF, INF, 0, 7},
                                {4, INF, INF, 0}}};
    array<array<int, n>, n> L0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                L0[i][j] = 0;
            }
            else{
                L0[i][j] = INF;
            }
        }
    }

    array<array<int, n>,n> result1 = slow_apsp(W, L0);
    array<array<int, n>,n> result2 = faster_apsp(W);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}