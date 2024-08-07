#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // trip构建0diff
        vector<int> diff(1001);
        int maxLen = 0;
        for(auto trip : trips){
            int inc = trip[0];
            int startIndex = trip[1];
            int endIndex = trip[2] - 1;
            maxLen = max(maxLen, endIndex);
            diff[startIndex] += inc;
            if(endIndex + 1 < 1001){
                diff[endIndex + 1] -= inc;
            }
 
        }
        vector<int> res(maxLen + 1);
        res[0] = diff[0];
        int maxRes = max(0, res[0]);
        if(maxRes > capacity){
            return false;
        }
        for(int i = 1; i < maxLen + 1; i++){
            res[i] = res[i - 1] + diff[i];
            maxRes = max(maxRes, res[i]);
            if(maxRes > capacity){
                return false;
            }
        } 
        return true;
        
    }
};


int main(){

    vector<vector<int>> v = {{{100,0,1},{100,0,1}}};
    Solution* s = new Solution();
    s->carPooling(v, 4);

    return 0;
}