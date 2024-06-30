#include<bits/stdc++.h>

using namespace std;

class Solution {
    int findMin(vector<int> &nums) {
        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums.back()) right = mid; // 蓝色
            else left = mid; // 红色
        }
        return right;
    }

    int lower_bound(vector<int> &nums, int left, int right, int target) {
        while (left + 1 < right) { // 开区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid; // 范围缩小到 (mid, right)
            else
                right = mid; // 范围缩小到 (left, mid)
        }
        return nums[right] == target ? right : -1;
    }

public:
    int search(vector<int> &nums, int target) {
        int i = findMin(nums), left, right;
        if (target > nums.back()) left = -1, right = i; // 左段
        else left = i - 1, right = nums.size(); // 右段
        return lower_bound(nums, left, right, target);
    }
};
