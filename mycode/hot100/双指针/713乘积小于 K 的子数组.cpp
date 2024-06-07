#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1){
            return 0;
        }
        int res = 0;
        int l = 0;
        int sum = 1;
        for(int i = 0; i < nums.size(); i++){
            sum *= nums[i];
            while (sum >= k)
            {
                sum /= nums[l];
                l++;
                /* code */
            }
            res += i - l + 1;
        }
        return res;
    }
};