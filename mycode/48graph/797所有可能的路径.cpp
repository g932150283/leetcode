#include<bits/stdc++.h>

using namespace std;



class Solution {

    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>>& graph, int index){
        // index 遍历的结点，已经添加到了path中
        if(index == graph.size() - 1){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < graph[index].size(); i++){
            path.push_back(graph[index][i]);
            dfs(graph, graph[index][i]);
            path.pop_back();
        }

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};