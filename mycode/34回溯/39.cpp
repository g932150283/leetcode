#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startindex){
        if(getSum(path) == target){
            res.push_back(path);
            return;
        }
        if(getSum(path) > target){
            return;
        }
        for(int i = startindex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }

    int getSum(vector<int>& path){
        int sum = 0;
        for(int p : path){
            sum += p;
        }
        return sum;
    }
};