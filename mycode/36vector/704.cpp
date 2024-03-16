#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int res = -1;
        while (l < r)
        {
            
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                l = mid;
                break;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                // nums[mid] > target
                r = mid - 1;
            }
            

            /* code */
        }
        if(nums[l] == target){
                res = l;
        }
        return res;
        
    }
};