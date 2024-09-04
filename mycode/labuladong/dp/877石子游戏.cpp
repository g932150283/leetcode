#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = {piles[i], 0};
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                int left = piles[i] + dp[i + 1][j].second;
                int right = piles[j] + dp[i][j - 1].second;
                if(left > right){
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                }else{
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        pair<int, int> res = dp[0][n - 1];
        return res.first - res.second > 0 ? true : false;
    }
};