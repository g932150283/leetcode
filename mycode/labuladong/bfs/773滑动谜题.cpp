#include <bits/stdc++.h>

using namespace std;

class Solution
{
    string swap(string s, int adj, int idx)
    {
        char tmp = s[adj];
        s[adj] = s[idx];
        s[idx] = tmp;
        return s;
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}};
        int m = 2, n = 3;
        int step = 0;
        string target = "123450";
        string start = "";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                start += to_string(board[i][j]);
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                if (cur == target)
                {
                    return step;
                }
                int idx = 0;
                while (cur[idx] != '0')
                {
                    idx++;
                    /* code */
                }
                // exchange
                for (int adj : neighbor[idx])
                {
                    string nxt = swap(cur, adj, idx);
                    if (!visited.count(nxt))
                    {
                        q.push(nxt);
                        visited.insert(nxt);
                    }
                }
            }
            step++;

            /* code */
        }
        return -1;
    }
};
