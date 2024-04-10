#include<bits/stdc++.h>

using namespace std;


void getRes(int n, int m){
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // 排列数，先遍历背包，再遍历物品
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
            }
            
        }
    }
    cout << dp[n] << endl;
}

int main(){

    int n, m;
    while (cin >> n >> m)
    {
        getRes(n, m);
        /* code */
    }
    



    return 0;
}