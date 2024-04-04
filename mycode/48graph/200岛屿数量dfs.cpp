#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        if(visited[x][y] || grid[x][y] == '0'){
            return;
        }
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()
                || grid[nextx][nexty] == '0'){
                    continue;
                }
            dfs(grid, visited, nextx, nexty);
        }
        
            /* code */
        
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    result++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;

    }
};


int main(){

    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    return 0;
}