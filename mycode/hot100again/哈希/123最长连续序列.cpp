#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int num : nums){
            uset.insert(num);
        }
        int res = 0;
        for(int num : uset){
            int cur = num;
            if(!uset.count(cur - 1)){
                while (uset.count(cur + 1))
                {
                    cur++;

                    /* code */
                }
                res = max(res, cur - num + 1);
                
            }
        }
        return res;
    }
};