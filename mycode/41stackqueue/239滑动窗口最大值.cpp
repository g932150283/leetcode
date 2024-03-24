#include<bits/stdc++.h>

using namespace std;

class MyQueue
{
private:
    /* data */
    deque<int> q;
public:
    void pop(int val){
        if(!q.empty() && val == q.front()){
            q.pop_front();
        }
    }

    void push(int val){
        
        while (!q.empty() && q.back() < val)
        {
            q.pop_back();
            /* code */
        }
        q.push_back(val);
        
    }

    int front(){
        return q.front();
    }

};

class Solution {
private:
    vector<int> res;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int j;
        // int maxres, cnt, prt;
        // for(int i = 0; i <= nums.size() - k; i++){
        //     maxres = INT_MIN;
        //     cnt = k;
        //     prt = i;
        //     while (cnt--)
        //     {
        //         maxres = max(nums[prt], maxres);
        //         prt++;
        //         /* code */
        //     }
        //     res.push_back(maxres);
                        
        // }
        // return res;
        // 超时
        MyQueue mq;
        for(int i = 0; i < k; i++){
            mq.push(nums[i]);
        }
        res.push_back(mq.front());
        for(int i = k; i < nums.size(); i++){
            //移除上一个元素
            mq.pop(nums[i - k]);
            // 添加当前元素
            mq.push(nums[i]);
            // 获取最大元素
            res.push_back(mq.front());
        }
        return res;
    }
};