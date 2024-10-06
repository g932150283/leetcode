#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size() - 3; i++){
            int x = nums[i];
            if(i > 0 && x == nums[i - 1]){
                continue;
            }
            if(x + nums[i + 1] + nums[i + 2] > 0){
                break;
            }
            if(x + nums[nums.size() - 1] + nums[nums.size() - 2] < 0){
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = x + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    res.push_back({x, nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                        /* code */
                    }
                    k--;
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                        /* code */
                    }
                    
                    
                }
                /* code */
            }
            
        }
        return res;
    }
};