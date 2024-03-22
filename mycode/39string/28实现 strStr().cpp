#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while (j > 0 && s[i] != s[j])
            {
                // 回退
                j = next[j - 1];
                /* code */
            }
            if(s[i] == s[j]){
                j++;
                
            }
            next[i] = j;
            
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        if(needle.size() == 0){
            return 0;
        }

        getNext(next, needle);

        int j = 0;
        for (int i = 0; i < haystack.size(); i++){
            /* code */
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
                /* code */
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
            
        }

        return -1;
        
    }



};