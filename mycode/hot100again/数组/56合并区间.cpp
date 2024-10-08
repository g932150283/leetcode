class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[0] < b[0]; 
        });
        vector<vector<int>> res;
        for(vector<int>& interval : intervals){
            //效率：避免了不必要的内存拷贝，尤其是当intervals中的元素是较大的向量时。
            //原地修改：通过引用，你可以直接修改intervals中的元素，而不是在修改时创建一个新的副本。
            if(res.size() == 0){
                res.push_back(interval);
                continue;
            }
            if(res.back()[1] >= interval[0]){
                res.back()[1] = max(res.back()[1], interval[1]);
                continue;
            }
            res.push_back(interval);
        }
        return res;
    }
};
