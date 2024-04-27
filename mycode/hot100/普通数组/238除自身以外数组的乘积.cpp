#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        if(nums.size() == 0){
            return res;
        }
        res[0] = 1;
        int tmp = 1;
        /*
        res[0]     1     nums[1]   nums[2]    nums[3]
        res[1]  nums[0]     1      nums[2]    nums[3]
        res[2]  nums[0]  nums[1]     1        nums[3]
        res[3]  nums[0]  nums[1]   nums[2]      1
        */
       // 下三角
       for(int i = 0; i < nums.size(); i++){
            res[i] = res[i - 1] * nums[i - 1];
       }
       // 上三角
       for(int i = nums.size() - 2; i >= 0; i++){
            tmp = tmp * nums[i + 1];
            res[i] = res[i] * tmp;
       }
       return res;
    }
};