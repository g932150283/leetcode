#include<bits/stdc++.h>

using namespace std;

class Solution {
    int getMax(vector<int>& nums, int begin, int end){
        if(begin == end) return nums[begin];
        vector<int> dp(nums.size());
        dp[begin] = nums[begin];
        dp[begin + 1] = max(nums[begin + 1], nums[begin]);
        for(int i = begin + 2; i <= end; i++){
            dp[i] = max(dp[i -1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int res1 = getMax(nums, 0, nums.size() - 2);
        int res2 = getMax(nums, 1, nums.size() - 1);
        return max(res1, res2);

    }
};

