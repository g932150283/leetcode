#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y){
        if(visited[x][y]){
            return;
        }
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()){
                continue;
            }
            if(heights[x][y] > heights[nextx][nexty]){
                continue;
            }
            dfs(heights, visited, nextx, nexty);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        /*
              pac
        pac        atl
              atl
        */

        for(int i = 0; i < n; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m -1);
        }

        for(int i = 0; i < m; i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n - 1, i);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};