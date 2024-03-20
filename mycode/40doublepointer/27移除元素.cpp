#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0;
        for(int q = 0; q < nums.size(); q++){
            if(nums[q] != val){
                nums[s] = nums[q];
                s++;
            }
        }
        return s;
    }
};