#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        visited[x][y] = 1;
        q.push({x, y});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nextx = x + dir[i][0];
                int nexty = y + dir[i][1];
                if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n){
                    continue;
                }
                if(visited[nextx][nexty] == 0 && grid[nextx][nexty] == '1'){
                    q.push({nextx, nexty});
                    visited[nextx][nexty] = 1;
                }
            }
            /* code */
        }
        
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    res++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return res;

    }
};