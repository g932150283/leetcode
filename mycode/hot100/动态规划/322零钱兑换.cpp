#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1)); // -1 表示没有访问过
        auto dfs = [&](auto&& dfs, int i, int c) -> int {
            if (i < 0) {
                return c == 0 ? 0 : INT_MAX / 2; // 除 2 防止下面 + 1 溢出
            }
            int &res = memo[i][c]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            if (c < coins[i]) {
                return res = dfs(dfs, i - 1, c);
            }
            return res = min(dfs(dfs, i - 1, c), dfs(dfs, i, c - coins[i]) + 1);
        };
        int ans = dfs(dfs, n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};