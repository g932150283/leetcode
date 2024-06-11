#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 入 保持单调性，从左到右递减
        // 存的为下标
        // 出 当前下标-队首元素下标 >= k 队首元素出队
        // 加入答案 当前下标 >= k - 1
        vector<int> res;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            // ru
            while (!q.empty() && nums[q.back()] <= nums[i]){
                /* code */
                q.pop_back();
            }
            q.push_back(i);
            // chu
            if(i - q.front() >= k){
                q.pop_front();
            }
            // jiadaan
            if(i >= k - 1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};  