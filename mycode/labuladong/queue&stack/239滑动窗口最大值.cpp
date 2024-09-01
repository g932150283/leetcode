#include <bits/stdc++.h>

using namespace std;


class MonotonicQueue{

    list<int> maxq;
public:
    int max(){
        return maxq.front();
    }
    void push(int x){
        while (!maxq.empty() && maxq.back() < x)
        {
            maxq.pop_back();
            /* code */
        }
        maxq.push_back(x);
        
    }
    void pop(int x){
        if(x == maxq.front()){
            maxq.pop_front();
        }
    }

};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue que;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                que.push(nums[i]);
            }else{
                que.push(nums[i]);
                res.push_back(que.max());
                que.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};  