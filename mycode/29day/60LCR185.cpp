#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<double> statisticsProbability(int num) {
        vector<double> pre(6, 1.0 / 6);
        for(int i = 2; i <= num; i++){
            vector<double> dp(5 * i + 1, 0);
            for(int j = 0; j < pre.size(); j++){
                for(int k = 0; k < 6; k++){
                    dp[j + k] = dp[j + k] + pre[j] * 1.0 / 6;
                }
            }
            pre = dp;
        }
        return pre;
    }
    
};

int main(){
    Solution* s = new Solution();
    s->statisticsProbability(2);
    return 0;
}