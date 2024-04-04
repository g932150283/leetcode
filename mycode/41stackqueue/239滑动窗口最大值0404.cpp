#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
public:
    deque<int> que; // 使用deque来实现单调队列

    // 单调队列存放窗口值
    //  push pop front
    void push(int x)
    {
        while (!que.empty() && x > que.back())
        {
            que.pop_back();
            /* code */
        }
        que.push_back(x);
        
    }

    void pop(int x){
        if (!que.empty() && x == que.front())
        {
            que.pop_front();
            /* code */
        }
        
    }

    int front(){
        return que.front();

    }
};

class Solution
{
private:
    vector<int> res;

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        MyQueue q;
        for(int i = 0; i < k; i++){
            q.push(nums[i]);
        }
        res.push_back(q.front());
        for(int i = k; i < nums.size(); i++){
            q.pop(nums[i - k]);
            q.push(nums[i]);
            res.push_back(q.front());
        }
        return res;
    }
};