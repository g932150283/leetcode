#include<bits/stdc++.h>

using namespace std;


class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return res;
    }
};