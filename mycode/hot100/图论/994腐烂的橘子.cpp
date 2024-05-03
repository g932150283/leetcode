#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        int fresh = 0;
        int min = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int num = q.size();
            bool rotten = false;
            for(int i = 0; i < num; i++){
                auto x = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nextx = x.first + dir[j][0];
                    int nexty = x.second + dir[j][1];
                    if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == 1){
                        grid[nextx][nexty] = 2;
                        q.push({nextx, nexty});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten){
                min++;
            }
            /* code */
        }
        if(fresh){
            return -1;
        }else{
            return min;
        }
        
    }

};