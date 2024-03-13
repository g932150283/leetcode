#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }

    void backtracking(int k, int n, int start){
        if(path.size() == k && (sumVector(path) == n)){
            res.push_back(path);
            return;
        }
        for(int i = start; i < 10; i++){
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }

    int sumVector(vector<int>& v){
        int sum = 0;
        for(auto vec : v){
            sum += vec;
        }
        return sum;
    }
};