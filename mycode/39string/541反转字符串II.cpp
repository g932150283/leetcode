#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i = i + 2 * k){
            if(s.size()- 1 - i < k){
                reverse(s.begin() + i, s.end());
            }else if(s.size()- 1 - i > k && s.size()- 1 - i < 2 * k){
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};