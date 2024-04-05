#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string output;
        int number = 0;
        for(char c : s){
            if(c == ' '){
                number += 1;
                if(number == k){
                    break;
                }
            }
            output += c;
        }
        return output;
    }
};


int main(){

    string s = "chopper is not a tanuki";
    int k = 5;

    Solution solution;
    string result = solution.truncateSentence(s, k);

    cout << result << endl;

    return 0;
}