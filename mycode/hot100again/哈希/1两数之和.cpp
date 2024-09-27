#include <bits/stdc++.h>

using namespace std;
/*

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(target - nums[i]))
            {
                if (umap[target - nums[i]] != i)
                {

                    return {i, umap[target - nums[i]]};
                }
            }
        }
        return {};
    }
};