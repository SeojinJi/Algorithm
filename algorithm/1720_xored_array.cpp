#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> output;
        output.push_back(first);
        int number = first;
        for(int num : encoded){
            number = number ^ num;
            output.push_back(number);
        }
        return output;
    }
};


int main(){

    vector<int> encoded = {6,2,7,3};
    int first = 4;

    Solution solution;
    vector<int> result = solution.decode(encoded, first);

    for(int num : result){
        cout << num << " ";
    }

    return 0;
}