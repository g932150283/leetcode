#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 装满容量为amount的背包有至少需要的硬币
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // 遍历顺序，先物品后背包，组合数
        //          先背包后物品，排列数
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j -coins[i]] + 1, dp[j]);
                }
            }
        }

        return dp[amount];
    }
};