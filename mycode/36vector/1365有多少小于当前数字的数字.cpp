#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--) { // 从后向前，记录 vec[i] 对应的下标
            hash[vec[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            vec[i] = hash[nums[i]];
        }
        return vec;


        
    }
};


int main(){

    vector<int> v = {8,1,2,2,3};
    Solution* s = new Solution();
    s->smallerNumbersThanCurrent(v);
    return 0;
}