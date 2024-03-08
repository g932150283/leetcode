#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res(nums1.size(), -1);
        if(nums1.size() == 0){
            return res;
        }

        // key 元素 value 下标
        unordered_map<int, int> umap;
        for(int i = 0; i < nums1.size(); i++){
            umap[nums1[i]] = i;
        }

        s.push(0);
        for(int i = 0; i < nums2.size(); i++){
            while (!s.empty() && nums2[i] > nums2[s.top()]){
                if(umap.count(nums2[s.top()]) > 0){
                    int index = umap[nums2[s.top()]];
                    res[index] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};