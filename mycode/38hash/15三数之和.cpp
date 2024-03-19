#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else{
                    // res.push_back({i, l, r});
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    r--;
                    l++;
                }
            }
            
        }
        return res;
    }
};