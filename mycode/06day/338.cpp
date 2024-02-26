#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1, 0);
        for(int i = 1; i <= n; i++){
            v[i] = v[i & (i - 1)] + 1;
        }
        return v;
    }
};

int main(){

    Solution s;
    auto v = s.countBits(5);
    for(auto vv : v){
        cout << vv << " ";
    }
    cout << endl;


    return 0;
}