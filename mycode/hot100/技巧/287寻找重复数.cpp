#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[0];
        fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            /* code */
        }
        fast = 0;
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
            /* code */
        }
        return slow;
        
        
    }
};