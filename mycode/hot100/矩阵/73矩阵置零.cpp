#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<vector<int>> zero;
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix[0].size(); j++){
        //         if(matrix[i][j] == 0){
        //             zero.push_back({i, j});
        //         }
        //     }
        // }
        // for(auto z : zero){
        //     int row = z[0];
        //     int col = z[1];
        //     for(int i = 0; i < matrix.size(); i++){
        //         if(matrix[i][col] != 0){
        //             matrix[i][col] = 0;
        //         }
        //     }
        //     for(int j = 0; j < matrix[0].size(); j++){
        //         if(matrix[row][j] != 0){
        //             matrix[row][j] = 0;
        //         }
        //     }
        // }
        vector<int> row(matrix.size()), col(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = col[j] = 1;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
    }
};