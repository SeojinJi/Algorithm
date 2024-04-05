#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largest = 0;
        int height = 0;
        for(int num : gain){
            height += num;
            if(largest < height){
                largest = height;
            }
        }
        return largest;
    }
};

int main(){
    vector<int> gain = {-4,-3,-2,-1,4,3,2};

    Solution solution;
    int result = solution.largestAltitude(gain);

    cout << result << endl;
    return 0;
}