#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for(char ch : magazine){
            map[ch]++;
        }

        for(char ch : ransomNote){
            map[ch]--;
            if(map[ch] < 0){
                return false;
            }
        }
        return true;
    }
};