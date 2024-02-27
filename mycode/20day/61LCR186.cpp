#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        unordered_set<int> repeat;
        int ma = 0, mi = 14;
        for(int place : places){
            if(place == 0){
                continue;
            }
            ma = max(ma, place);
            mi = min(mi, place);
            if(repeat.find(place) != repeat.end()){
                return false;
            }
            repeat.insert(place);
        }
        return ma - mi < 5;
    }
};

int main(){

    vector<int> v = {2,2,1,1,1,2,2};
    Solution* s = new Solution();
    cout << s->checkDynasty(v);
    return 0;
}