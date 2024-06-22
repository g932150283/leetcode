#include<bits/stdc++.h>

using namespace std;

class Solution {
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    vector<string> res;
    string path;
    void backtracing(const string& digits, int index){
        if(index == digits.size()){
            res.push_back(path);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++){
            path.push_back(letters[i]);
            backtracing(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        backtracing(digits, 0);
        return res;
    }
};