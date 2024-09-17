#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
            index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int other = target - nums[i];
            if(index.count(other)){
                if(index[other] != i){
                    return {i, index[other]};
                }
            }
        }
        return {};
    }
};