#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if (abs(target) > sum){
            return 0;
        } 
        if((sum + target) % 2 == 1){
            return 0;
        }
        int l = (sum + target) / 2;

        vector<int> dp(l + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = l; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[l];


        
    }
};

