#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> output;
        while(!deck.empty()){
            int number = deck.back();
            deck.pop_back();
            if(output.size() > 1){
                int lastnumber = output.back();
                output.pop_back();
                output.insert(output.begin(), lastnumber);
            }
            output.insert(output.begin(), number);
        }
        return output;
    }
};


int main(){

    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};

    Solution solution;
    vector<int> result = solution.deckRevealedIncreasing(deck);

    for(int num : result){
        cout << num << " ";
    }

    return 0;
}