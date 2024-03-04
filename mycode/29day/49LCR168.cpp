#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int a = 0, b = 0, c = 0;
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int dpa = dp[a] * 2;
            int dpb = dp[b] * 3;
            int dpc = dp[c] * 5;
            int dpmin = min(min(dpa, dpb), dpc);
            if(dpmin == dpa){
                a++;
            }
            if(dpmin == dpb){
                b++;
            }
            if(dpmin == dpc){
                c++;
            }

            dp[i] = dpmin;
        }
        return dp[n - 1];
    }



};

int main(){
    Solution* s = new Solution();
    cout << s->nthUglyNumber(10);
    return 0;
}