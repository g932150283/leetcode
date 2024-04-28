#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int l =  0;
        int r = matrix[0].size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        while (true)
        {
            // right
            for(int i = l; i <= r; i++){
                res.push_back(matrix[t][i]);
            }
            if(t + 1 > b){
                break;
            }else{
                t++;
            }
            // down
            for(int i = t; i <= b; i++){
                res.push_back(matrix[i][r]);
            }
            if(r - 1 < l){
                break;
            }else{
                r--;
            }
            // left
            for(int i = r; i >= l; i--){
                res.push_back(matrix[b][i]);
            }
            if(b - 1 < t){
                break;
            }else{
                b--;
            }
            // up
            for(int i = b; i >= t; i--){
                res.push_back(matrix[i][l]);
            }
            if(l + 1 > r){
                break;
            }else{
                l++;
            }
            /* code */
        }
        return res;
        
    }
};