#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }

        // 第一个0的位置
        int zero = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(zero >= 0){
                    swap(nums[i], nums[zero]);
                    zero++;
                }
            }else{
                if(zero < 0){
                    zero = i;
                }
            }
            // if(nums[i] == 0){
            //     if(zero < 0){
            //         zero = i;
            //     }
            // }else{
            //     if(zero >= 0){
            //         swap(nums[i], nums[zero]);
            //         zero++;
            //     }
                
            // }
        }
        


    }
};