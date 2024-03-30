#include<bits/stdc++.h>

using namespace std;

class Solution {

    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    continue;
                }
                for(char k = '1'; k <= '9'; k++){
                    if(isValid(i, j, k, board)){
                        board[i][j] = k;
                        if(backtracking(board)){
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    
                }
                return false;
            }
            return true;
        }
        
    }

    bool isValid(int row, int col, char k, vector<vector<char>>& board){
        // 行有无重复
        for(int i = 0; i < board[0].size(); i++){
            if(board[row][i] == k){
                return false;
            }
        }
        // 列有无重复
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] == k){
                return false;
            }
        }

        // 9宫格内是否重复
        int startI = row / 3 * 3;
        int startJ = col / 3 * 3;
        for(int i = startI; i < startI + 3; i++){
            for(int j = startJ; j < startJ + 3; j++){
                if(board[i][j] == k){
                    return false;
                }
            }
        }

        return true;



    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

