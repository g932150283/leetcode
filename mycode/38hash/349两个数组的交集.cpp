#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set 去重
        unordered_set<int> result;
        unordered_set<int> numsset(nums1.begin(), nums1.end());
        for(int num : nums2){
            if(numsset.find(num) != numsset.end()){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};