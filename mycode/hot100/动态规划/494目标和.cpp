#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int m = sum + target;
        if(m % 2 != 0){
            return 0;
        }
        if(abs(target) > sum){
            return 0;
        }
        vector<int> dp(m / 2 + 1, 0);
        // 初始化， 装满容量为0的背包有1种装法——什么也不放
        dp[0] = 1;
        // 先物品后背包
        for(int i = 0; i < nums.size(); i++){
            for(int j = m / 2; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[m / 2];
    }
};