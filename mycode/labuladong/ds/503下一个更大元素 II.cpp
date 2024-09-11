#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 2 * n - 1; i >= 0; i--){
            while (!s.empty() && s.top() <= nums[i % n])
            {
                s.pop();
                /* code */
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]); 
            
        }
        return res;
    }
};