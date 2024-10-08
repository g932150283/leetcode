#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int premin = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            res = max(res, pre-premin);
            premin = min(premin, pre);
        }
        return res;
    }
};