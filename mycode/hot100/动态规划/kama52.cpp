#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, v;
    while (cin >> n >> v)
    {
        vector<int> weight;
        vector<int> value;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            weight.push_back(a);
            value.push_back(b);
        }
        vector<int> dp(v + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = weight[i]; j <= v; j++){
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        /* code */
        cout << dp[v] << endl;
    }
    


    return 0;
}