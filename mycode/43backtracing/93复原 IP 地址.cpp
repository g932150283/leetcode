#include<bits/stdc++.h>

using namespace std;

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(delim, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

std::vector<int> ipToIntegerArray(const std::string &ip) {
    std::vector<std::string> parts = split(ip, '.');
    std::vector<int> result;
    for (const auto &part : parts) {
        result.push_back(std::stoi(part));
    }
    return result;
}

class Solution {
private:
    vector<string> res;
    string path;
    // strNum 字段数量
    void backtracking(const string& s, int startIndex, int strNum){
        if(strNum == 4 && path.size() == s.size() + 3){
            std::vector<int> ipIntArray = ipToIntegerArray(path);
            // for (const auto &part : ipIntArray) {
            //     if(part > 255){
            //         return;
            //     }
            // }
            res.push_back(path);
            return;
        }

        if(strNum > 4){
            return;
        }


        for(int i = startIndex; i < s.size(); i++){
            string str = s.substr(startIndex, i - startIndex + 1);
            if(isIP(str, 0, str.size() - 1)){
                if(strNum == 3){
                    str = str;
                }else{
                    str = str + '.';
                }

                path = path + str;
                strNum++;
                backtracking(s, i + 1, strNum);
                strNum--;
                path.erase(path.rfind(str), str.length());

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
            if(num > 255){
                cout << num << endl;
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