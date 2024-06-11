#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int premin = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            // 更新前缀和
            pre += nums[i];
            // 更新结果， 当前前缀和-最小前缀和
            res = max(res, pre-premin);
            // 更新最小前缀和
            premin = min(premin, pre);
        }
        return res;
    }
};