#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        int dpi2 = 0;
        int dpi1 = 0;
        int dpi = 0;
        for(int i = 0; i < n; i++){
            dpi = max(dpi1, dpi2 + nums[i]);
            dpi2 = dpi1;
            dpi1 = dpi;
        }
        return dpi;
    }
};