#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0, n = nums.size();
        while (fast < n)
        {
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
            /* code */
        }
        while (slow < n)
        {
            nums[slow++] = 0;
            /* code */
        }
        
        
    }
};