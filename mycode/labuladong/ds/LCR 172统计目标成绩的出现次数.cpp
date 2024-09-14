#include<bits/stdc++.h>

using namespace std;

class Solution {
    // zuobianjie
    int low(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            /* code */
            if(nums[mid] == target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid;
            }
        }
        if(l == nums.size()){
            return -1;
        }
        return nums[l] == target ? l : -1;
        
    }

public:
    int countTarget(vector<int> &nums, int target) {
        int start = low(nums, target); // 使用其中一种写法即可
        int end = low(nums, target + 1);
        return end - start;
    }
};
