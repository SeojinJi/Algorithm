#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int num : arr){
            cout << num << " ";
        }
        cout << endl;
        vector<vector<int>> output;
        int minDiff = arr[1] - arr[0];
        for(int i = 0; i < arr.size()-1; i++){
            int Diff = arr[i+1] - arr[i];
            if(minDiff > Diff){
                minDiff = Diff;
                output.clear();
                vector<int> minRow = {arr[i], arr[i+1]};
                output.push_back(minRow);
            }
            else if(Diff == minDiff){
                vector<int> minRow = {arr[i], arr[i+1]};
                output.push_back(minRow);
            }
        }
        return output;
    }
};


int main(){
    vector<int> arr = {-17,46,63,81,-101,-91,121,-2,112,-15,-65,-96,6,-139};

    Solution solution;
    vector<vector<int>> result = solution.minimumAbsDifference(arr);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}