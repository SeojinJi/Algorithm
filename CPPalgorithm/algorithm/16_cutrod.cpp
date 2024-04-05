#include <iostream>
#include <vector>
#define MAX 101
#define INF -1e9

using namespace std;

int r[MAX];
int v[MAX];
int s[MAX];


int cut_rod_dc(int p[], int n){
    if(n == 0){
        return 0;
    }

    int q = INF;

    for(int i = 1; i <= n; i++){
        if(q == INF || q < p[i] + cut_rod_dc(p, n-i)){
            q = p[i] + cut_rod_dc(p, n-i); // q = max{q, p[i] + cut_rod_dc(p, n-i)}
        }
    }

    return q;

}

int memoized_cut_rod_aux(int p[], int n, int r[]){
    if(r[n] >= 0){ // already solution?
        return r[n];
    }
    int q = INF;
    if(n == 0){
        q = 0;
    }
    for(int i = 1; i <= n; i++){ // i is the position of the first cut
        if(q == INF || q < p[i] + memoized_cut_rod_aux(p, n-i, r)){
            q = p[i] + memoized_cut_rod_aux(p, n-i, r);
        }
    }
    r[n] = q; // remember the solution value for length n
    return q;
}


int memoized_cut_rod(int p[], int n){
    fill(r, r+MAX, -1); // will remember solution values in r
    return memoized_cut_rod_aux(p, n, r);
}

int bottom_up_cut_rod(int p[], int n){
    fill(r, r+MAX, -1); // will remember solution values in r
    r[0] = 0;
    for(int j = 1; j <= n; j++){ // for increasing rod length j
        int q = INF;
        for(int i = 1; i <= j; i++){ // i is the position of the first cut
            if(q == INF || q < p[i] + r[j-i]){
                q = p[i] + r[j-i]; // q = max{q, p[i] + r[j-i]}
            }
        }
        r[j] = q; // remember the solution value for length j
    }

    return r[n];
}

int extended_bottom_up_cut_rod(int p[], int n){
    fill(r, r+MAX, -1);
    fill(s, s+MAX, -1);
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = INF;
        for(int i = 1; i <= j; i++){
            if(q == INF || q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    return r[n]; 
}


int main(void){
    int n, m; // n : 가격표에 기재된 길이 끝까지, m : rod 길이
    cin >> n >> m;
    
    v[0] = 0;

    for(int i = 1; i <= n; i++){ // 우선 가격표 다 받아주고요
        int a;
        cin >> a;
        v[i] = a;
    }

    int cost = extended_bottom_up_cut_rod(v, m);

    for(int i = 1; i <= m; i++){
        cout << i << "cut at " << s[i] << " and maximum cost will be " << r[i] << endl;
    }

    // cout << m << " costs " << cost << endl;

    return 0;

}