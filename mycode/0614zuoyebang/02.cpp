#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> dp(n + 1);
        if(n == 1){
            dp[1] = 1;
        }else if(n == 2){
            dp[1] = 1;
            dp[2] = 2;
        }else if(n == 3){
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
        }else{
            // vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            for(int i = 4; i <= n; i++){
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
        }
        
        cout << dp[n] << endl;
    }
    
}
// 64 位输出请用 printf("%lld")