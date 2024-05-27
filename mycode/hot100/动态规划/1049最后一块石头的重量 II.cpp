#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i : stones){
            sum += i;
        }
        int w = sum / 2;
        vector<int> dp(w + 1, 0);
        for(int i = 0; i < stones.size(); i++){
            for(int j = w; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[w] - dp[w];
    }
};