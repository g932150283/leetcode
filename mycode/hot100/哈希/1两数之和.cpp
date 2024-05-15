#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            auto it = umap.find(target - nums[i]);
            if(it != umap.end()){
                return {it->second, i};
            }else{
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};