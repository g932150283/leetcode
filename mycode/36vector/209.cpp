#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin = 0;// 起始位置
        int res = INT_MAX;
        int sum = 0;
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            while (sum >= target)
            {
                l = i - begin + 1;
                res = min(l, res);
                sum = sum - nums[begin];
                begin++; // 起始位置后移
                /* code */
            }
            
        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
    }
};