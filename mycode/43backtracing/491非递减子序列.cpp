#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }

        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back())
                || (uset.find(nums[i]) != uset.end())){
                    // 不符合不加入
                    continue;
                }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

    }
};