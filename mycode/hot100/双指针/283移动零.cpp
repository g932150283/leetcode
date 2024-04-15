#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }
        // 指向第一个零
        int cur = -1;
        // 指向最后一个0后面
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(cur > -1){
                    swap(nums[i], nums[cur]);
                    cur++;
                }
            }else if(cur < 0){
                cur = i;
            }
        }
        
        


    }
};