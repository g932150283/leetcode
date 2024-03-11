#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0){
            return true;
        }
        int cover = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            cover = max(cover, nums[i] + i);
            if(cover >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};