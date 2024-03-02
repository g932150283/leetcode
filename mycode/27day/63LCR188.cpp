#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestTiming(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }

    int bestTiming1(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        // dp[i][0] 买入股票后所剩余额，是一个负数，越大越好（负数越大越接近0）
        // dp[i][1] 卖出股票后所获利润，是一个正数，越大越好，最终结果
        vector<vector<int> > dp(prices.size(), vector<int>(2, INT_MIN));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            // 前一天已经买入 or 今天买入 花费最小
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // 前一天已经卖出 or 今天卖出 收入最高
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        for(auto d : dp){
            for(auto p : d){
                cout << p << " ";
            }
            cout << endl;
        }
        return dp[prices.size() - 1][1];
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> grid = {3,6,2,9,8,5};
    cout << s->bestTiming1(grid) << endl;
    return 0;
}