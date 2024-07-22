#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double ans = INT_MIN, mx = 1, mi = 1;
        for (auto& x : nums)
        {
            if (x < 0) swap(mx, mi);
            mx = max(mx * x, (double)x), mi = min(mi * x, (double)x);
            ans = max(ans, mx);
        }
        return (int)ans;
    }
};