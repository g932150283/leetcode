#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = -1;
        int right = nums.size() - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums.back()) 
                right = mid; // 蓝色
            else 
                left = mid; // 红色
        }
        return nums[right];
    }
};
