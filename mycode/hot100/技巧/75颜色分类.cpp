#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return;
        }

        int zero = 0;
        int i = 0; 
        int two = n;
        while (i < two)
        {
            // 三个区间
            // [0, zero]  0
            // [zero, i]  1
            // [two, n-1] 2
            if(nums[i] == 2){
                two--;
                swap(nums[i], nums[two]);
            }else if(nums[i] == 0){
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            }else{
                i++;
            }
        }
        
    }
};

