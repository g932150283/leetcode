#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> res;
    string path;
    vector<char> vchar= {'(', ')'};

    void backtracking(int l, int r, int n){
        if(l > n || r > n || l < r){
            return;
        }
        if(path.size() == 2 * n){
            res.push_back(path);
        }

        for(char ch : vchar){
            path.push_back(ch);
            if(ch == '('){
                backtracking(l + 1, r, n);
            }else{
                backtracking(l, r + 1, n);
            }
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        return res;
    }
};