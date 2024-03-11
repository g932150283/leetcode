#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int next = 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            next = max(next, i + nums[i]);
            if(i == cur){
                res++;
                cur = next;
                if(next >= nums.size() - 1){
                    break;
                }
            }
        }
        return res;
    }
};