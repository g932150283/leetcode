#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        
        for(int quick = 0; quick < nums.size(); quick++){
            if(nums[quick] != val){
                nums[slow] = nums[quick];
                slow++;
            }
        }
        return slow;
    }
};