#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> result;
    string s;

    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return result;
    }

    void backtracking(const string& digits, int index){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }

        // index 转换为 数字
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
};