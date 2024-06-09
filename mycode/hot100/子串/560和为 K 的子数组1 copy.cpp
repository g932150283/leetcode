#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        int sum = 0;
        for(int num : nums){
            sum += num;
            if(umap.count(sum - k)){
                res += umap[sum - k];
            }
            umap[sum]++;
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