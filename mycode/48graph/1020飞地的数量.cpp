#include<bits/stdc++.h>

using namespace std;

class Solution {
    int res;
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void dfs(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        res++;
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid.size()){
                continue;
            }
            if(grid[nextx][nexty] == 0){
                continue;
            }
            dfs(grid, nextx, nexty);
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // 上下两行
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                dfs(grid, i, 0);
            }
            if(grid[i][m - 1] == 1){
                dfs(grid, i, m - 1);
            }
        }
        // 左右两行
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                dfs(grid, 0, j);
            }
            if(grid[n - 1][j] == 1){
                dfs(grid, n - 1, j);
            }
        }
        //清空计数
        res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};