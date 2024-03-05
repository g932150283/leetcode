#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;

        while (left <= right)
        {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if(leftmax < rightmax){
                res = res + leftmax - height[left];
                left++;
            }else{
                res = res + rightmax - height[right];
                right--;
            }
            /* code */
        }
        return res;
        


    }
};


// dp
// int trap(vector<int>& height) {
//         int res = 0;
//         int n = height.size();
        
//         if(n == 0){
//             return res;
//         }
        
//         vector<int> leftMax(n);
//         vector<int> rightMax(n);
//         leftMax[0] = height[0];
//         rightMax[n - 1] = height[n - 1];

//         for(int i = 1; i < n; i++){
//             leftMax[i] = max(height[i], leftMax[i - 1]);
//         }

//         for(int i = n - 2; i >=0; i--){
//             rightMax[i] = max(height[i], rightMax[i + 1]);
//         }

//         for(int i = 0; i < n; i++){
//             res = res + min(leftMax[i], rightMax[i]) - height[i];
//         }

//         return res;

//     }