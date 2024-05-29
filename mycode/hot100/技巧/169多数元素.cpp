#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int veto = 0;
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(veto == 0){
                tmp = nums[i];
                veto++;
            }else if(tmp == nums[i]){
                veto++;
            }else{
                veto--;
            }
        }
        return tmp;
    }
};