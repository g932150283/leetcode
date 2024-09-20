#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = height[0];
        int rmax = height[n - 1];
        int res = 0;
        while (l <= r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax){
                res = res + lmax - height[l];
                l++;
            }else{
                res = res + rmax - height[r];
                r--;
            }
            /* code */
        }
        return res;
        
    }
};