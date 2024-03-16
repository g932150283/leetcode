#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int rear = nums.size() - 1;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            if(nums[l] * nums[l] > nums[r] * nums[r]){
                res[rear] = nums[l] * nums[l];
                l++;
                rear--;
            }else{
                res[rear] = nums[r] * nums[r];
                r--;
                rear--;
            }
            /* code */
        }
        return res;
        
    }
};

int main(){

    vector<int> v = {-7,-3,2,3,11};
    Solution* s = new Solution();
    s->sortedSquares(v);
    return 0;
}