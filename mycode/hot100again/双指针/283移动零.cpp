#include<bits/stdc++.h>

using namespace std;
/*

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        while (r < n)
        {
            if(nums[r] != 0){
                nums[l] = nums[r];
                l++;
            }
            r++;
            /* code */
        }
        while (l < n)
        {
            nums[l++] = 0;
            /* code */
        }
        
        
        
    }
};