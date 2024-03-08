#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }

    bool dfs(vector<int>& arr, int start, vector<bool>& visited){
        if(arr[start] == 0){
            return true;
        }
        
        if(start < 0 || start >= arr.size() || visited[start] == true){
            return false;
        }

        visited[start] = true;
        return dfs(arr, start + arr[start], visited) || dfs(arr, start - arr[start], visited);
        
    }
};


