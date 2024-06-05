#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        for(int i : nums){
            set.insert(i);

        }
        int res = 0;
        for(int i : set){
            int cur = i;
            if(!set.count(cur - 1)){
                while (set.count(cur + 1))
                {
                    cur++;
                    /* code */
                }
                res = max(res, cur - i + 1);
                
            }
        }
        return res;
    }
};