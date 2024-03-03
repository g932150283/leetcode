#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int dismantlingAction(string arr) {
        unordered_map<char, int> dic;
        vector<int> dp(arr.size());
        dp[0] = 1;
        dic[arr[0]] = 0;
        int res = 0;
        for(int i = 1; i < arr.size(); i++){
            if(dic.find(arr[i]) == dic.end()){
                dp[i] = dp[i + 1];
            }else{
                int index = dic.find(arr[i])->second;
                if(i - index > dp[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                }else{
                    dp[i] = i - index;
                }
            }
            // 更新下标
            dic[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main(){
    Solution* s = new Solution();
    string arr1 = "dbascDdad";
    string arr2 = "KKK";
    string arr3 = "pwwkew";
    cout << s->dismantlingAction(arr1) << endl;
    cout << s->dismantlingAction(arr2) << endl;
    cout << s->dismantlingAction(arr3) << endl;
    return 0;
}