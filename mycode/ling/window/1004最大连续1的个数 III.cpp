#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, left = 0, cnt0 = 0;
        for (int right = 0; right < nums.size(); right++) {
            cnt0 += 1 - nums[right]; // 0 变成 1，用来统计 cnt0
            while (cnt0 > k) {
                cnt0 -= 1 - nums[left++];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
