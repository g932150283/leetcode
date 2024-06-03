#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return;
        }
        int i = n - 2;
        int j = n - 1;
        int k = j;
        // nums[i] < nums[j]
        while (i >= 0 && nums[i] >= nums[j])
        {
            i--;
            j--;
            /* code */
        }
        if(i >= 0){
            // nums[i] < nums[k]
            while (nums[i] >= nums[k])
            {
                k--;
                /* code */
            }
            swap(nums[i], nums[k]);
        }
        i = j;
        j = n - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
            /* code */
        }
        
        
    }
};

int main(){

    Solution* s = new Solution();
    vector<int> i = {3, 2, 1};
    s->nextPermutation(i);
    return 0;
}