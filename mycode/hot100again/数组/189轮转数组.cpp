#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        auto reverse = [&](int i, int j){
            while (i < j)
            {
                swap(nums[i++], nums[j--]);
                /* code */
            }
            
        };
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }
};