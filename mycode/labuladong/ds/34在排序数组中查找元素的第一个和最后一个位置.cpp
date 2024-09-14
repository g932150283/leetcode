#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int lowbound(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return -1;
        }
        int l = 0, r = n;
        while (l < n)
        {
            int mid = l + (l - r) / 2;
            if(nums[mid] == target){
                r = mid;
            }else if(nums[mid] > target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
            /* code */
            if(l == n){
                return -1;
            }
            return nums[l] == target ? l : -1;
        }
    }
    int upperbound(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return -1;
        }
        int l = 0, r = n;
        while (l < n)
        {
            int mid = l + (l - r) / 2;
            if(nums[mid] == target){
                l = mid + 1;
            }else if(nums[mid] > target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }
            /* code */
        }
        if(l == 0){
            return -1;
        }
        return nums[l - 1] == target ? l - 1 : -1;
        
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2);
        res[0] = lowbound(nums, target);
        res[1] = upperbound(nums, target);
        return res;
    }
};