#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moer投票法
        int veto = 0;
        int x = 0;
        for(int num : nums){
            if(veto == 0){
                x = num;
            }
            if(x == num){
                veto++;
            }else{
                veto--;
            }
        }
        return x;
    }
};