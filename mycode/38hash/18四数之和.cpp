#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            if(nums[i] >= 0 && nums[i] > target){
                return res;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target){
                    return res;
                }
                // j去重
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    if(nums[i] + nums[j] + nums[l] + nums[r] > target){
                        r--;
                    }else if(nums[i] + nums[j] + nums[l] + nums[r] < target){
                        l++;
                    }else{
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
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

                    /* code */
                }
                

            }
        }
        return res;
    }
};