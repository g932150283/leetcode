#include<bits/stdc++.h>

using namespace std;


/*

第一行包含两个整数，N，V，分别表示研究材料的种类和行李空间 

接下来包含 N 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值


*/

int getMax(vector<int>& weight, vector<int>& value, int n, int v){

    vector<int> dp(v + 1, 0);
    // 先物品后背包
    for(int i = 0; i < n; i++){
        // 正序完全背包
        for(int j = weight[i]; j <= v; j++){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[v];


    return 0;
}

int main(){

    int n, v;
    while (cin >> n >> v)
    {
        vector<int> weight(n);
        vector<int> value(n);

        for(int i = 0; i < n; i++){
            cin >> weight[i] >> value[i];
        }

        cout << getMax(weight, value, n, v) << endl;


        /* code */
    }
    

    return 0;
}