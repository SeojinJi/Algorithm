#include <iostream>
#include <array>
#include <limits>
#define INF 10000


using namespace std;

const int n = 5; 

void print_all_pairs_shortest_path(array<array<int, n>,n> P, int i, int j){
    if(i == j){
        cout << i << " -> ";
    }
    else if(P[i][j] == -1){
        cout << "no path from " << i << " to " << j << " exists";
    }
    else{
        print_all_pairs_shortest_path(P, i, P[i][j]);
        cout << j << " -> ";
    }
}

array<array<int, n>,n> floyd_warshall_pred(array<array<int, n>,n> W){
    array<array<int, n>, n> D;
    array<array<int, n>, n> P;

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

    print_all_pairs_shortest_path(P, 0, 3);

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    return D;

}


int main(void){
    array<array<int, n>, n> W  = {{{0, 3, 8, INF, -4},
                                {INF, 0, INF, 1, 7},
                                {INF, 4, 0, INF, INF},
                                {2, INF, -5, 0, INF},
                                {INF, INF, INF, 6, 0}}};

    array<array<int, n>,n> result = floyd_warshall_pred(W);

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}


