#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<int> radiant;
        vector<int> dire;
        string output;
        for(int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R'){
                radiant.push_back(i);
            }
            else{
                dire.push_back(i);
            }
        }
        int number = senate.size();
        while(!radiant.empty() and !dire.empty()){
            int r = radiant.front();
            int d = dire.front();
            radiant.erase(radiant.begin());
            dire.erase(dire.begin());
            if (r < d){
                radiant.push_back(number);
            }
            else{
                dire.push_back(number);
            }
            number += 1;
        }
        if(radiant.empty()){
            output = "Dire";
        }
        else{
            output = "Radiant";
        }
        return output;
    }
};


int main(){

    string senate = "RDD";

    Solution solution;
    string result = solution.predictPartyVictory(senate);

    cout << result << endl;

    return 0;
}