#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string result = "";
        for(int i = 0; i < words.size(); i++){
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            if (words[i] == reversed){
                return words[i];
            }
            
        }
        return result;
    }
};

int main(){
    vector<string> words = {"abc","car","ada","racecar","cool"};

    Solution solution;
    string result = solution.firstPalindrome(words);

    cout << result << endl;
    return 0;
}