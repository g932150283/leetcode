#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 先遍历背包后遍历物品得到排列数
        // 先遍历物品后遍历背包得到组合数

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};