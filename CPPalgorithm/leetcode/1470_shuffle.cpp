#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for(int i = 0; i < n; i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};

int main(){

    vector<int> nums = {1,2,3,4,4,3,2,1};
    int n = 4;

    Solution solution;
    vector<int> result = solution.shuffle(nums, n);

    for(int num : result){
        cout << num << " ";
    }

    return 0;
}