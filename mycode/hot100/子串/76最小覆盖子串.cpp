#include<bits/stdc++.h>

using namespace std;

class Solution {
    bool isCovered(int cntS[], int cntT[]){
        for(int i = 'A'; i <= 'Z'; i++){
            if(cntS[i] < cntT[i]){
                return false;
            }
        }
        for(int i = 'a'; i <= 'z'; i++){
            if(cntS[i] < cntT[i]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int ansLeft = -1;
        int ansRight = m;
        int left = 0;
        int cntS[128]{};
        int cntT[128]{};
        for(char ch : t){
            cntT[ch]++;
        }
        for(int right = 0; right < m; right++){
            cntS[s[right]]++;
            while (isCovered(cntS, cntT))
            {
                if(right - left < ansRight - ansLeft){
                    ansLeft = left;
                    ansRight = right;
                }
                cntS[s[left]]--;
                left++;
                /* code */
            }
            
        }
        if(ansLeft < 0){
            return "";
        }else{
            return s.substr(ansLeft, ansRight - ansLeft + 1);
        }
    }
};