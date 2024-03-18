
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            hash[t[i] - 'a']--;
        }

        for(int h : hash){
            if(h != 0){
                return false;
            }
        }

        return true;
    }
};