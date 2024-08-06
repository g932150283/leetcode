#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        int n = nums.size();
        while (fast < n)
        {
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
            /* code */
        }
        return ++slow;
        
    }
};