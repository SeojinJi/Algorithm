#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<int> data {10, 20, 30, 40, 50};
    vector<int> data2;

    for(int val : data){
        cout << val << " ";
    }
    cout << endl;


    reverse(data.begin(), data.begin() + 3);

    // cout << data.empty() << endl; // 0 (거짓)
    // cout << data2.empty() << endl; // 1 (참)

    // cout << data.size() << endl; // 5
    // cout << data.capacity() << endl; // 5

    for(int val : data){
        cout << val << " ";
    }
    cout << endl;

    // cout << data.front() << endl;
    // cout << data.back() << endl;

    // data.push_back(60);
    
    // cout << data.size() << endl; // 6
    // cout << data.capacity() << endl; // 10

    // for(int val : data){
    //     cout << val << " ";
    // }
    // cout << endl;

    // data.pop_back();

    // cout << data.size() << endl; // 5
    // cout << data.capacity() << endl; // 10

    // for(int val : data){
    //     cout << val << " ";
    // }
    // cout << endl;
    
    // cout << (data.back() - 1) << endl;
    // cout << data.back() << endl;
    
    return 0;
}