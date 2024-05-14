#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> h;
        for(auto n : nums){
            if(h.size() == k && h.top() >= n){
                continue;
            }
            if(h.size() == k){
                h.pop();
            }
            h.push(n);
        }
        return h.top();
        for(int i = 0; i < k; i++){
            h.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            if(h.top() >= nums[i]){
                continue;
            }else{
                h.pop();
                h.push(nums[i]);
            }
        }
        return h.top();
    }
};
