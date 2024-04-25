#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string greatestLetter(string s) {
        // write code here
        vector<string> ss = {"A", "B", "C", "D", "E",
                             "F", "G", "H", "I", "J",
                             "K", "L", "M", "N", "O",
                             "P", "Q", "R", "S", "T", 
                             "U", "V", "W", "X", "Y", "Z"};
        vector<int> big(26, 0);
        vector<int> small(26, 0);
        for(char ch : s){
            if(ch - 'A' >= 0 && ch - 'A' <= 25){
                big[ch - 'A']++;
            }else{
                small[ch - 'A' - 32]++;
            }
        }
        for(int i = 25; i >= 0; i--){
            if(big[i] > 0 && small[i] > 0){
                return ss[i];
            }
        }
        return "";
    }
};


int main(){

    Solution* s = new Solution();
    s->greatestLetter("TaoMe");

    return 0;
}