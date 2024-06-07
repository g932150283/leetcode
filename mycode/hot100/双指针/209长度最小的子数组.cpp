#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;
        int l = 0; 
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while (sum >= target)
            {
                res = min(res, i - l + 1);
                sum -= nums[l];
                l++;
                /* code */
            }
        }
        if(res == n + 1){
            return 0;
        }else{
            return res;
        }
    }
};