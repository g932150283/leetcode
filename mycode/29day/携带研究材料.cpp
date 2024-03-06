#include<bits/stdc++.h>

using namespace std;

// m 物品个数 n 容量
// dp[i][j] 0-i个物品 背包容量为j时最大价值
int getmaxdp2(vector<int>& weight, vector<int>& value, int m, int n){
    vector<vector<int> > dp(m, vector<int>(n + 1, 0));
    for(int j = weight[0]; j <= n; j++){
        dp[0][j] = value[0];
    }

    for(int i = 1; i < m; i++){
        for(int j = 0; j <= n; j++){
            // 背包容量 小于 物品重量
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j - weight[i]] + value[i];
            }
            
        }
    }

    return dp[m - 1][n];
    
}

int getmaxdp1(vector<int>& weight, vector<int>& value, int m, int n){
    // 容量为j的背包的最大价值
    vector<int> dp(n+1);
    dp[0] = 0;
    //先物品后背包
        // 背包容量倒序，否则物品多次放入
    for(int i = 0; i < m; i++){
        for(int j = n; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[n];

}


int main(){

    // int m, n;
    // cin >> m >> n;
    // vector<int> weight(m);
    // vector<int> value(m);

    // for(int i = 0; i < m; i++){
    //     cin >> weight[i];
    // }

    // for(int i = 0; i < m; i++){
    //     cin >> value[i];
    // }

    vector<int> weight{2, 2, 3, 1, 5, 2};
    vector<int> value{2, 3, 1, 5, 4, 3};
    getmaxdp1(weight, value, 6, 1);

    return 0;
}