#include <bits/stdc++.h>

using namespace std;
class NumArray {
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1);
        for(int i = 1; i < preSum.size(); i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */