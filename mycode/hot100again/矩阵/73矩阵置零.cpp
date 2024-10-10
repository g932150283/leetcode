#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 记录第一行第一列是否全部为0
        // 遍历第一行第一列以外的数据，如果有0，修改第一行第一列对应位置
        // 根据第一行第一列修改matrix
        // 修改第一行第一列
        if (matrix.size() == 0) return;

        bool firstrow = false;
        bool firstcol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[i][j];
                if(tmp == 0){
                    if(i == 0){
                        firstrow = true;
                    }
                    if(j == 0){
                        firstcol = true;
                    }
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrow){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(firstcol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        
        
    }
};

// int main(){

// }