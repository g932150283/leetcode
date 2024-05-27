#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if(sum % 2 != 0){
            return false;
        }
        int w = sum / 2;
        vector<int> dp(w + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = w; j >= 0; j--){
                if(j < nums[i]){
                    continue;
                }else{
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        if(dp[w] == w){
            return true;
        }else{
            return false;
        }

    }
};