#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int lmax = 0;
        int rmax = 0;
        while (l <= r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax){
                res += min(lmax, rmax) - height[l];
                l++;
            }else{
                res += min(lmax, rmax) - height[r];
                r--;
            }
            /* code */
        }
        return res;
        
    }
};