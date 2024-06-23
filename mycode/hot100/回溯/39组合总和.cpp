#include<bits/stdc++.h>


using namespace std;


class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtracing(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracing(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracing(candidates, target, 0, 0);
        return res;
    }
};