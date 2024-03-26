#include<bits/stdc++.h>

using namespace std;


static bool cmp(int a, int b){
    return abs(a) > abs(b);
}

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), cmp);
        
        for(int i = 0; i < nums.size(); i++){
            if(k > 0 && nums[i] < 0){
                k--;
                nums[i] = -nums[i];
            }
        }

        while (k > 0)
        {
            nums[nums.size() - 1] = - nums[nums.size() - 1];
            k--;
            /* code */
        }
        

        int res = 0;
        for(int a : nums){
            res += a;
        }
        
        return res;
    }
};