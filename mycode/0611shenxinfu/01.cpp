#include <bits/stdc++.h>
using namespace std;
/*
abcde
a,bb,acd,ace

3
*/
int main() {
    string s, sub;
    while (cin >> s >> sub) { // 注意 while 处理多个 case
       vector<int> index;
        for(int i = 0; i < sub.size(); i++){
            if(sub[i] == ','){
                index.push_back(i);
            }
        }
        vector<string> ss;
        ss.push_back(sub.substr(0, index[0]));
        for(int i = 0; i < index.size(); i++){
            if(i == index.size() - 1){
                ss.push_back(sub.substr(index[i] + 1, sub.size()));
                continue;
            }
            ss.push_back(sub.substr(index[i] + 1, index[i + 1] - index[i] - 1));
        }
        unordered_map<char, int> umap;
        for(char ch: s){
            umap[ch]++;
        }
        int res = 0;
        for(string sss : ss){
            int flag = 0;
            unordered_map<char, int> umap1;
            umap1.clear();
            for(char ch: sss){
                umap1[ch]++;
            }
            for(char ch: sss){
                if(umap1[ch] != umap[ch]){
                    flag = 1;
                }
            }
            if(flag == 0){
                res++;
            }
        }
        cout << res << endl;
    }
}
// 64 位输出请用 printf("%lld")