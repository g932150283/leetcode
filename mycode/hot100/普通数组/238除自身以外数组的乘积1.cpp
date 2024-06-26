#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> suf(n);
        // suf[n - 1] = 1;
        // // vector<int> pre(n);
        // // pre[0] = 1;
        // int pre = 1;
        // for(int i = n - 2; i >= 0; i--){
        //     suf[i] = suf[i + 1] * nums[i + 1];
        // }
        // for(int i = 0; i < n; i++){
        //     suf[i] = suf[i] * pre;
        //     pre = pre * nums[i];
        // }
        // return suf;
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = 1;
        vector<int> pre(n);
        pre[0] = 1;
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            suf[i] = suf[i + 1] * nums[i + 1];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = pre[i] * suf[i];
        }
        return res;

    }
};
