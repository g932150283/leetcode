#include<bits/stdc++.h>

using namespace std;


class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtracing(vector<int>& nums, int index){
        res.push_back(path);
        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracing(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracing(nums, 0);
        return res;
    }
};