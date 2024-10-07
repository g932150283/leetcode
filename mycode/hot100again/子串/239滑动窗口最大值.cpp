#include <bits/stdc++.h>

using namespace std;


class MonotonicQueue{

    deque<int> q;
public:
    void push(int x){
        while (!q.empty() && q.back() < x){
            q.pop_back();
        }
        q.push_back(x);
    }
    int max(){
        return q.front();
    }
    void pop(int x){
        if(x == q.front()){
            q.pop_front();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                q.push(nums[i]);
            }else{
                q.push(nums[i]);
                res.push_back(q.max());
                // 移除第一个入队的
                q.pop(nums[i - k + 1]);
            }
        }
        return res;
    }

};  