#include<bits/stdc++.h>

using namespace std;

class Solution {
    string plusOne(string s, int j){
        s[j] = s[j] == '9' ? '0' : s[j] + 1;
        return s;
    }
    string minusOne(string s, int j){
        s[j] = s[j] == '0' ? '9' : s[j] - 1;
        return s;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while (!q.empty())
        {
            int se = q.size();
            for(int i = 0; i < se; i++){
                string cur = q.front();
                q.pop();
                if(deads.count(cur)){
                    continue;
                }
                if(cur == target){
                    return step;
                }
                for(int j = 0; j < 4; j++){
                    string up = plusOne(cur, j);
                    if(!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
            /* code */
        }
        return -1;
        
    }
};