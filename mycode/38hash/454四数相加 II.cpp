#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        int count = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                map[sum]++;
            }
        }

        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                int sum = nums3[i] + nums4[j];
                sum = -1 * sum;
                if(map.find(sum) != map.end()){
                    count += map[sum];
                }
            }
        }
        return count;
    }
};