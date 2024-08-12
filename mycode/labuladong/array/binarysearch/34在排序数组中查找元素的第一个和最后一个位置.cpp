#include<bits/stdc++.h>

using namespace std;

class Solution {
    int left_bound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                // 上边界不断左移
                r = mid;
            }else if(nums[mid] > target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
            /* code */
        }
        if(l < 0 || l >= nums.size()){
            return -1;
        }
        return nums[l] == target ? l : -1;
    }
    int right_bound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                // 下边界不断右移动
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
            /* code */
        }
        if(l - 1 < 0 || l -1 >= nums.size()){
            return -1;
        }
        return nums[l - 1] == target ? (l - 1) : -1;
        
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);
        return res;

    }
};