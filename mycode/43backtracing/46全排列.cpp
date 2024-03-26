#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    // void backtracking(vector<int>& nums){
    //     if(path.size() == nums.size()){
    //         res.push_back(path);
    //         return;
    //     }

    //     for(int i = 0; i < nums.size(); i++){
    //         if(find(path.begin(), path.end(), nums[i]) == path.end()){
    //             // 找不到则添加
    //             path.push_back(nums[i]);
    //             backtracking(nums);
    //             path.pop_back();
    //         }
    //     }

    // }
    void backtracking(vector<int>& nums, vector<int>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i] == 0){
                // 没有用过则添加
                path.push_back(nums[i]);
                used[i]++;
                backtracking(nums, used);
                used[i]--;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size());
        backtracking(nums, used);
        return res;
    }
};