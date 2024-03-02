
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        // 横纵坐标
        int m = grid.size();
        int n = grid[0].size();
        // target长度
        int l = target.size();
        // 访问标识数组
        vector<vector<bool> > visited(m, vector<bool>(n, false));

        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool{
            if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] != target[k]){
                return false;
            }
            if(k == l - 1){
                return true;
            }
            visited[i][j] = true;
            // 上下左右  上 i, j-1 下 i, j+1 左 i-1, j 右 i+1, j
            bool res = dfs(i, j - 1, k + 1) || dfs(i, j + 1, k + 1) || dfs(i - 1, j, k + 1) || dfs(i + 1, j, k + 1);

            visited[i][j] = false;
            return res;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    return 0;
}