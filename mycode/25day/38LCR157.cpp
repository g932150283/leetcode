#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> goodsOrder(string goods) {
        vector<char> path;
        vector<string> res;
        vector<bool> visited(goods.size(), false);

        sort(goods.begin(), goods.end());

        function<void(int)> dfs = [&](int k){
            if(k == goods.size()){
                res.push_back(string(path.begin(), path.end()));
                return;
            }
            for(int i = 0; i < goods.size(); i++){
                // 剪枝
                if(i > 0 && goods[i] == goods[i - 1] && visited[i - 1]){
                    continue;
                }
                if(!visited[i]){
                    visited[i] = true;
                    path.push_back(goods[i]);
                    dfs(k+1);
                    path.pop_back();
                    visited[i] = false;
                }
            }
        };

        dfs(0);
        return res;
    }
};

int main(){

    Solution* s = new Solution();
    s->goodsOrder("abac");
    return 0;
}