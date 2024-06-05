#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string s : strs){
            string ss = s;
            sort(s.begin(), s.end());
            umap[s].push_back(ss);
        }
        vector<vector<string>> res;
        res.reserve(umap.size());
        for(auto it = umap.begin(); it != umap.end(); it++){
            res.push_back(it->second);
        }
        return res;
        
    }
};