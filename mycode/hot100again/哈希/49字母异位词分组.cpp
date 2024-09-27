#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string str : strs){
            string s = str;
            sort(s.begin(), s.end());
            umap[s].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it = umap.begin(); it != umap.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};