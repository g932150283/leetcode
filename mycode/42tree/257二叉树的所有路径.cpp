#include<bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    /* data */
};

class Solution {
    vector<string> res;
    vector<int> path;

    void backtracking(TreeNode* root){
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            string spath;
            for(int i = 0; i < path.size() - 1; i++){
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }

        

        if(root->left){
            backtracking(root->left);
            path.pop_back();
        }

        if(root->right){
            backtracking(root->right);
            path.pop_back();
        }
        

    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtracking(root);
        return res;
    }
};