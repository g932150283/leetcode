#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<string> res;
    string path;
    // pointNum 字段数量
    void backtracking(const string& s, int startIndex, int pointNum){
        if(pointNum == 3 && path.size() == s.size() + 3){
            if(isIP(s, startIndex, s.size() - 1)){
                res.push_back(path);
                return;
            }
            
        }


        for(int i = startIndex; i < s.size(); i++){
            if(isIP(s, startIndex, i)){
                s.insert(s.begin() + i + 1 , '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);   
                pointNum--;                         
                s.erase(s.begin() + i + 1);

            }else{
                break;
            }
        }
    }

    bool isIP(const string& str, int start, int end){
        if(start > end){
            return false;
        }

        if(str[start] == '0' && start != end){
            return false;
        }

        int num = 0;

        for(int i = start; i < end; i++){
            if(str[i] > '9' || str[i] < '0'){
                return false;
            }
            num = num * 10 + (str[i] - '0');
            // cout << num << endl;
            if(num > 255){
                
                return false;
            }
        }
        
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};


int main(){

    Solution* s = new Solution();
    string str = "25525511135";
    s->restoreIpAddresses(str);

    return 0;
}