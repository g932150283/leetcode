#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtracing(vector<int>& nums, vector<bool>& visited){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == true){continue;}
            visited[i] = true;
            path.push_back(nums[i]);
            backtracing(nums, visited);
            path.pop_back();
            visited[i] = false;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size());
        backtracing(nums, visited);
        return res;
    }
};