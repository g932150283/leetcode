#include<bits/stdc++.h>

using namespace std;

class Solution {
    int getRes(vector<int>& nums, int l, int r){
        int dpi2 = 0;
        int dpi1 = 0;
        int dpi = 0;
        for(int i = l; i <= r; i++){
            dpi = max(dpi1, dpi2 + nums[i]);
            dpi2 = dpi1;
            dpi1 = dpi;
        }
        return dpi;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 0){
            return 0;
        }
        return max(getRes(nums, 0, n - 2), getRes(nums, 1, n - 1));

    }
};

