#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex, int vecnum){
        if(vecnum == nums.size() && find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
            return;
        }else if(find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }

        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            vecnum++;
            backtracking(nums, i + 1, vecnum);
            vecnum--;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0, 0);
        return res;
    }
};