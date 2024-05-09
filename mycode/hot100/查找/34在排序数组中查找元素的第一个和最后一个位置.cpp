#include<bits/stdc++.h>

using namespace std;

class Solution {
    int search(vector<int>& nums, int target, int lower){
        int res = -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target && lower == 1){
                res = mid;
                r = mid - 1;
            }else if(nums[mid] == target){
                res = mid;
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
                        /* code */
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int minindex = search(nums, target, 1);
        if(minindex == -1){
            return res;
        }
        int maxindex = search(nums, target, 0);
        res[0] = minindex;
        res[1] = maxindex;
        return res;
        
    }
};