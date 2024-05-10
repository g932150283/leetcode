#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> s2p;
        unordered_map<char, string> p2s;
        int l = 0;
        for(char ch : pattern){

            if(l >= s.size()){
                return false;
            }
            int r = l;
            while (r < s.size() && s[r] != ' ')
            {
                r++;
                /* code */
            }
            string tmp = s.substr(l, r - l);
            if(s2p.count(tmp) && s2p[tmp] != ch){
                return false;
            }
            if(p2s.count(ch) && p2s[ch] != tmp){
                return false;
            }
            s2p[tmp] = ch;
            p2s[ch] = tmp;
            l = r + 1;
            
        }
        return l >= s.size();
    }

};

int main(){

   string pattern = "abba";

   string s = "dog cat cat dog";
   Solution* ss = new Solution();
   ss->wordPattern(pattern, s);

    return 0;
}