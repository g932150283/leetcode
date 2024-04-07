
#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    // int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向
    void dfs(vector<vector<char>>& board, int x, int y){
        board[x][y] = 'A';
        for(int i = 0; i < 4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()){
                continue;
            }
            if(board[nextx][nexty] == 'X' || board[nextx][nexty] == 'A' ){
                continue;
            }
            dfs(board, nextx, nexty);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // 左右两列
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][m - 1] == 'O'){
                dfs(board, i, m - 1);
            }
        }
        // 上下两行
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[n -1][i] == 'O'){
                dfs(board, n - 1, i);
            }
        }



        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(board[i][j] != 'A'){
        //             board[i][j] == 'X';
        //         }
        //     }
        // }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }

            }
        }

    }
};