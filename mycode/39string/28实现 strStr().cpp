#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        for(int i = 0; i < haystack.size(); i++){
            for(int j = 0; j < needle.size(); j++){
                if(haystack[i] != needle[j]){
                    break;
                }else{
                    if(j == needle.size() -1){
                        return i - j;
                    }
                }
            }
        }
        return res;
    }
};