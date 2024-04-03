#include<bits/stdc++.h>

using namespace std;


// int getMax(vector<int>& weight, vector<int>& value, int bagsize){
//     int m = weight.size();
//     int n = bagsize;
//     // dp[i][j] 从0-i中取物品放入容量为j的背包的价值最大
//     vector<vector<int>> dp(m, vector<int>(n + 1, 0));
//     for(int i = weight[0]; i <= bagsize; i++){
//         dp[0][i] = value[0];
//     }

//     for(int i = 1; i < m; i++){
//         for(int j = 0; j <= n; j++){
//             if(j < weight[i]){
//                 dp[i][j] = dp[i - 1][j];
//             }else{
//                 dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
//             }
//         }
//     }
//     return dp[m - 1][n];

// }

int getMax2(vector<int>& weight, vector<int>& value, int bagsize){
    int m = weight.size();
    int n = bagsize;
    // dp[j] 容量为j的背包放的最大价值
    vector<int> dp(bagsize + 1, 0);

    for(int i = 0; i < m; i++){
        for(int j = bagsize; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[bagsize];

}

int main(){

    int size, bagsize;
    while (cin >> size >> bagsize)
    {
        vector<int> weight(size);
        vector<int> value(size);
        for(int i = 0; i < size; i++){
            cin >> weight[i];
        }
        for(int i = 0; i < size; i++){
            cin >> value[i];
        }

        // cout << getMax(weight, value, bagsize) << endl;
        cout << getMax2(weight, value, bagsize) << endl;

        
        /* code */
    }
    

    return 0;
}