#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        // 前缀和以及出现次数
        unordered_map<int, int> umap;
        umap[0] = 1;
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(umap.count(sum - k)){
                res += umap[sum - k];
            }
            umap[sum]++;

        }
        return res;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> v{1, 1, 1};
    s->subarraySum(v, 2);
    return 0;
}