#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0){
            return res;
        }
        // 上下左右边界
        int up = 0;
        int low = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (1)
        {
            for(int i = left; i <= right; i++){
                res.push_back(matrix[up][i]);
            }
            up++;
            if(up > low){
                break;
            }
            for(int i = up; i <= low; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(right < left){
                break;
            }
            for(int i = right; i >= left; i--){
                res.push_back(matrix[low][i]);
            }
            low--;
            if(low < up){
                break;
            }
            for(int i = low; i >= up; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
            if(left > right){
                break;
            }
        }
        return res;
        
        
    }
};