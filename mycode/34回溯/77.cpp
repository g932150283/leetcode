#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;        
    }

    void backtracking(int n, int k, int startIndex){
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; i++){
            // 处理
            path.push_back(i);
            // 递归
            backtracking(n, k, i+1);
            // 回溯
            path.pop_back();
        }
    }
};