#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int f = target - nums[i];
            auto iter = map.find(f);
            if(iter == map.end()){
                map[nums[i]] = i;
            }else{
                // res.push_back(map[f]);
                // res.push_back(i);
                return {iter->second, i};
            }
        }
        return {};
    }
};