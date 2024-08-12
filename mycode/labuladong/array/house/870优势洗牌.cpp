#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // 打得过就打，打不过就用最拉的
        int n = nums1.size();
        vector<int> res(n);
        vector<pair<int, int>> maxpq;
        for(int i = 0; i < n; i++){
            maxpq.push_back({nums2[i], i});
        }
        sort(maxpq.begin(), maxpq.end(), greater<pair<int, int>>());
        sort(nums1.begin(), nums1.end());
        int l = 0;
        int r = n - 1;
        for(auto& p : maxpq){
            int i = p.second;
            int val = p.first;
            if(val < nums1[r]){
                // 打得过
                res[i] = nums1[r];
                r--;
            }else{
                res[i] = nums1[l];
                l++;
            }
        }
        return res;
    }
};