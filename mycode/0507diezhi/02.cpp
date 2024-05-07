#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param originalStr string字符串 原始字符串
     * @return string字符串
     * "Nikki (happy) new (year)"
     * "Nikki (*) new (*)"
     */
    string ConvertString(string originalStr) {
        vector<char> v;
        int flag = 0; // 无(
        int num = 0;
        for(int i = 0; i < originalStr.size(); i++){
            char ch = originalStr[i];
            if(ch == '('){
                flag = 1;
                v.push_back(ch);
                int l = i + 1;
                while (l < originalStr.size() && (originalStr[l] != ')' || originalStr[l] != '('))
                {
                    num++;
                    /* code */
                    l++;
                }
                if(num > 0){
                    v.push_back('*');
                }
                
            }else if(ch == ')'){
                flag = 0;
                v.push_back(ch);
            }else if(flag == 0){
                v.push_back(ch);
            }else{
                num++;
            }
        }
        // for(char ch : originalStr){
        //     if(ch == '('){
        //         flag = 1;
        //         v.push_back(ch);
        //     }else if(ch == ')'){
        //         flag = 0;
        //         if(num != 0){
        //             v.push_back('*');
        //         }
        //         v.push_back(ch);
        //     }else if(flag == 0){
        //         v.push_back(ch);
        //     }else{
        //         num++;
        //     }
        // }
        string res = "";
        for(int i = 0; i < v.size(); i++){
            res += v[i];
        }
        return res;
    }
};