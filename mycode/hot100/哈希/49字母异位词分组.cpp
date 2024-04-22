#include<bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, int> getMap(string str){
        unordered_map<char, int> umap;
        for(char ch : str){
            umap[ch]++;
        }
        return umap;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            umap[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto it = umap.begin(); it != umap.end(); it++){
            res.emplace_back(it->second);
        }
        return res;
    }
};


int main(){

    Solution* s = new Solution();
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s->groupAnagrams(strs);
    return 0;
}