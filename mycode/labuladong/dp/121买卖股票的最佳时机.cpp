#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[0][0] = - prices[0];
        // for(int i = 1; i < n; i++){
        //     // 持有股票时手中的钱，越大越好
        //     dp[i][0] = max(dp[i - 1][0], -prices[i]);
        //     // 卖出股票时手中的钱，越多越好
        //     dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]);
        // }
        // return dp[n - 1][1];
        int minprice = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            minprice = min(minprice, prices[i]);
            res = max(res, prices[i] - minprice);
            // if(prices[i] > minprice){
            //     res = max(res, prices[i] - minprice);
            // }else{
            //     minprice = prices[i];
            // }
        }
        return res;
    }
};