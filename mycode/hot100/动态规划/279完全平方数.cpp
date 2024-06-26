#include<bits/stdc++.h>

using namespace std;
//如果求组合数就是外层for循环遍历物品，内层for遍历背包。

// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i * i <= n; i++){
            for(int j = i * i; j <= n; j++){
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};