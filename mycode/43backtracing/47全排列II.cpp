
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<int> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
            {
                continue;
            }
            if (used[i] == 0)
            {
                path.push_back(nums[i]);
                used[i]++;
                backtracking(nums, used);
                used[i]--;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> used(nums.size());
        backtracking(nums, used);
        return res;
    }
};