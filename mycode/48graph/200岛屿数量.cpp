#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        while (!que.empty())
        {   
            pair<int, int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for(int i = 0; i < 4; i++){
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()){
                    continue;
                }
                if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
            /* code */
        }
        
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
                    bfs(grid, visited, i, j);
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