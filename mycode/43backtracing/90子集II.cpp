#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> pathc;

    void backtracking(vector<int>& nums, int startIndex, int numres){
        

        if(numres == nums.size() && find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
            return;
        }
        if(find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }

        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            numres++;
            backtracking(nums, i + 1, numres);
            numres--;
            path.pop_back();
        }


    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, 0);
        return res;
    }
};


int main(){

    Solution* s = new Solution();
    vector<int> v = {4,1,0};
    s->subsetsWithDup(v);
    return 0;
}