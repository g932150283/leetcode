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
        unordered_set<string> q1, q2, visited;
        q1.insert("0000");
        q2.insert(target);
        int step = 0;
        while (!q1.empty() && !q2.empty())
        {
            unordered_set<string> tmp;
            for(string cur : q1){
                if(deads.count(cur)){
                    continue;
                }
                if(q2.count(cur)){
                    return step;
                }
                visited.insert(cur);
                for(int j = 0; j < 4; j++){
                    string up = plusOne(cur, j);
                    if(!visited.count(up)){
                        tmp.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if(!visited.count(cur)){
                        tmp.insert(down);
                    }
                }
            }
            step++;
            q1 = q2;
            q2 = tmp;
            /* code */
        }
        return -1;
        
        
    }
};