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
        // 一维遍历，只能先物品后背包，且背包要倒叙
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < m; i++){
            for(int j = n; j >= 0; j--){
                if(j < weight[i]){
                    continue;
                }else{
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
                
            }
        }
        cout << dp[n] << endl;
    }
    


    return 0;
}