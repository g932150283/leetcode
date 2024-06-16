#include<bits/stdc++.h>

using namespace std;


class Solution {
    bool isValid(string &s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255){
                return false;
            }

        }
        return true;
    }

    vector<string> res;
    void backtracing(string &s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                res.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                pointNum++;
                s.insert(s.begin() + i + 1, '.');
                backtracing(s, i + 2, pointNum);
                s.erase(s.begin() + i + 1);
                pointNum--;
            }else{
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracing(s, 0, 0);
        return res;
    }
};