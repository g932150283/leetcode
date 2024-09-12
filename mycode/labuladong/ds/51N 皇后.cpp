#include<bits/stdc++.h>

using namespace std;

class Solution {

    bool isValid(vector<string>& board, int row, int col){
        // 列
        int n = board.size();
        for(int i = 0; i <= row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // 右上
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // 左上
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> res;
    void backtrack(vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for(int i = 0; i < board.size(); i++){
            if(!isValid(board, row, i)){
                continue;
            }
            board[row][i] = 'Q';
            backtrack(board, row + 1);
            board[row][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};