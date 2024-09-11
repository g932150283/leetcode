#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> getGreater(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--){
            while (!s.empty() && s.top() <= nums[i])
            {
                s.pop();
                /* code */
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater = getGreater(nums2);
        unordered_map<int, int> greaterMap;
        for(int i = 0; i < nums2.size(); i++){
            greaterMap[nums2[i]] = greater[i];
        }
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            res[i] = greaterMap[nums1[i]];
        }
        return res;
    }
};