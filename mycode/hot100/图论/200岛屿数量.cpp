#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(grid[x][y] == '0' || visited[x][y] == 1){
            return;
        }
        visited[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n ){
                continue;
            }else{
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    res++;
                    dfs(grid, visited, i, j);
                }
                
            }
        }
        return res;

    }
};