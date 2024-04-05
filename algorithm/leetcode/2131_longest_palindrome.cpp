#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> palindrome;
        map<string, int> mirror;
        int result = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i][0] == words[i][1]){
                auto it = palindrome.find(words[i]);
                if(it == palindrome.end()){
                    palindrome[words[i]] = 1;
                }
                else{
                    palindrome[words[i]] += 1;
                }
            }
            else{
                auto it = mirror.find(words[i]);
                if(it == mirror.end()){
                    mirror[words[i]] = 1;
                }
                else{
                    mirror[words[i]] += 1;
                }
            }
        }
        for(auto it = mirror.begin(); it != mirror.end(); it++){
            string word = it->first;
            string mirrorword;
            mirrorword.push_back(word[1]);
            mirrorword.push_back(word[0]);
            auto mi = mirror.find(mirrorword);
            if(mi == mirror.end()){
                mirror[word] = 0;
            }
        }
        int num = 0;
        for(auto it = palindrome.begin(); it != palindrome.end(); it++){
            if(it->second % 2 == 1 && num == 0){
                result += (it->second * 2);
                num = 1;
            }
            else{
                result += ((it->second / 2) * 4);
            }
        }
        for(auto it = mirror.begin(); it != mirror.end(); it++){
            if(it->second == 0){
                continue;
            }
            string word = it->first;
            string mirrorword;
            mirrorword.push_back(word[1]);
            mirrorword.push_back(word[0]);
            int wrmin = min(mirror[word], mirror[mirrorword]);
            result += wrmin * 2;
        }
        return result;
    }
};

int main(){
    vector<string> words = {"lc","cl","gg"};

    Solution solution;
    int result = solution.longestPalindrome(words);
    
    cout << result << endl;
    return 0;
}