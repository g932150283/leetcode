#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int x = abs(nums[i]);
            if(nums[x - 1] > 0){
                nums[x - 1] = -nums[x - 1];
            }else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};