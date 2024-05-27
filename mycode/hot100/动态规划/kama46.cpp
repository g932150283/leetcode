#include<bits/stdc++.h>

using namespace std;

int main(){

    int m, n;
    while (cin >> m >> n)
    {
        vector<int> weight;
        vector<int> value;
        for(int i = 0; i < m; i++){
            int a;
            cin >> a;
            weight.push_back(a);
        }
        for(int i = 0; i < m; i++){
            int a;
            cin >> a;
            value.push_back(a);
        }
        // 定义
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        // 初始化
        for(int i = weight[0]; i <= n; i++){
            dp[0][i] = value[0];
        }
        // 遍历，先物品，后背包
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= n; j++){
                // 当前物品重量大于背包容量
                if(j < weight[i]){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);    
                }
            }
        }
        cout << dp[m - 1][n];
        /* code */
    }
    


    return 0;
}