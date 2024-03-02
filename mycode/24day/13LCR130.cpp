
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        return dfs(visited, m, n, cnt, 0, 0);
    }

    int dfs(vector<vector<bool> > &visited, int m, int n, int cnt, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || sums(i) + sums(j) > cnt){
            return 0;
        }
        visited[i][j] = true;
        int res = 1 + dfs(visited, m, n, cnt, i + 1, j) + dfs(visited, m, n, cnt, i, j + 1);
        return res;

    }
    int sums(int x){
        int res = 0;
        while (x > 0)
        {
            res += x % 10;
            x /= 10;
            /* code */
        }
        return res;
        
    }
};