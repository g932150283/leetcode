#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0, r = 1;
        if(nums.size() == 0){
            return 0;
        }
        while (r < nums.size())
        {
            if(nums[s] != nums[r]){
                s++;
                nums[s] = nums[r];
            }
            r++;
            /* code */
        }
        return s + 1;
        
        
    }
};