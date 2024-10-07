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