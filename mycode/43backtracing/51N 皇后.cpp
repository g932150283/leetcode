#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<string>> res;

    void backtracking(int n, int row, vector<string> &path)
    {
        if (row == n)
        {
            res.push_back(path);
        }

        for (int i = 0; i < n; i++)
        {
            if (isOK(row, i, path))
            {
                path[row][i] = 'Q';
                backtracking(n, row + 1, path);
                path[row][i] = '.';
            }
        }
    }

    bool isOK(int row, int col, vector<string> &str)
    {
        int n = str.size();
        for (int i = 0; i < row; i++)
        {
            if (str[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; j >= 0 && i >= 0; i--, j--)
        {
            if (str[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (str[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        path(n, string(n, '.'));
        backtracking(n, 0, path);
        return res;
    }
};