#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        vector<int> v(nums.size() + 1);
        // 前缀和
        for(int i = 0; i < nums.size(); i++){
            v[i + 1] = v[i] + nums[i];
        }
        unordered_map<int, int> umap;
        for(int i : v){
            if(umap.count(i - k)){
                res += umap[i - k];
            }
            umap[i]++;
        }
        return res;
    }
};

int main()
{
    vector<int> v = {3, 3, 3};
    Solution *s = new Solution();
    s->subarraySum(v, 3);
    return 0;
}