#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        vector<vector<int> > dp(frame.size(), vector<int>(frame[0].size()));
        dp[0][0] = frame[0][0];
        for(int i = 1; i < frame.size(); i++){
            dp[i][0] = dp[i - 1][0] + frame[i][0];
        }
        for(int j = 0; j < frame[0].size(); j++){
            dp[0][j] = dp[0][j - 1] + frame[0][j];
        }

        for(int i = 1; i < frame.size(); i++){
            for(int j = 1; j < frame[0].size(); j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i][j];
            }
        }
        return dp[frame.size() - 1][frame[0].size() - 1];
    }
};

int main(){
    Solution* s = new Solution();
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << s->jewelleryValue(grid) << endl;
    return 0;
}