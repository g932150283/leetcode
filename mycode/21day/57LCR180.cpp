#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        int i = 1, j = 2;
        vector<vector<int>> v;
        while (i < j)
        {
            int res = 0;
            for(int b = i; b <= j; b++){
                res = res + b;
            }
            if(res > target){
                i++;
            }else if(res < target){
                j++;
            }else{
                vector<int> v1;
                for(int b = i; b <= j; b++){
                    v1.push_back(b);
                }
                v.push_back(v1);
                i++;
            }
            /* code */
        }
        return v;
    }
};


int main(){
    Solution* s = new Solution();
    s->fileCombination(12);
    s->fileCombination(18);
    return 0;
}