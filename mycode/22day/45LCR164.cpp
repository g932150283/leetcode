#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string crackPassword(vector<int>& password) {
        vector<string> s;
        string res;
        for(int p : password){
            s.push_back(to_string(p));
        }
        sort(s.begin(), s.end(), [](string& x, string& y){ return x + y < y + x; });
        for(string ss : s){
            res += ss;
        }
        return res;
    }
};

int main(){

    vector<int> v = {0, 3, 30, 34, 5, 9};
    Solution* s = new Solution();
    s->crackPassword(v);
    return 0;
}