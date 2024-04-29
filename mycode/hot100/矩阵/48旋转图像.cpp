#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 上下翻转
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m / 2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[m - 1 - i][j]);
            }
        }
        // 对角线反转
        for(int i = 1; i < m; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


int main(){

    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    Solution* s = new Solution();
    s->rotate(v);
    return 0;
}