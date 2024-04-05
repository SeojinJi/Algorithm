#include <vector>
#include <iostream>
#include <algorithm>
#include <map> 

#define MAX_SIZE 2001

using namespace std;

class Solution{
    public :
        bool uniqueOccurrences(vector<int>& arr){
            int count[MAX_SIZE] = {0};
            bool seen[MAX_SIZE] = {false};

            for(int num : arr){
                count[num + 1000] += 1;
            }

            for(int i = 0; i < MAX_SIZE; i++){
                if(count[i] != 0){
                    if(seen[count[i]] != false){
                        return false;
                    }
                    else{
                        seen[count[i]] = true;
                    }
                }
            }
            return true;
        }
};

int main(){

    vector<int> arr = {1, 2};
    Solution solution;

    bool result = solution.uniqueOccurrences(arr);

    cout << result << endl;

    return 0;
}