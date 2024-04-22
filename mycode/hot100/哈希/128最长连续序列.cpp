#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(const int &n : nums){
            uset.insert(n);
        }
        int res = 0;
        for(const int &n : uset){
            if(!uset.count(n - 1)){
                int curNum = n;
                int curres = 1;
                while (uset.count(curNum + 1))
                {
                    curNum++;
                    curres++;
                    /* code */
                }
                res = max(res, curres);
                
            }
        }
        return res;
    }
};