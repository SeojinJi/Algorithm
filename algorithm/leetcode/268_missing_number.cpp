#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int number = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                return i;
            }
        }
        return number;
    }
};

int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};

    Solution solution;
    int result = solution.missingNumber(nums);

    cout << result << endl;
    return 0;
}