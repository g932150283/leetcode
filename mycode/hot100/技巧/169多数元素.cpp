#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        int res = 0;
        int num = -1;
        for(auto i : umap){
            if(i.second > res){
                res = i.second;
                num = i.first;
            }
        }
        return num;
    }
};