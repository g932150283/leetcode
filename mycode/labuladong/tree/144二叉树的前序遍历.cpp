#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.

 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void traverse(TreeNode* root, vector<int>& vec){
        if(root == nullptr){
            return;
        }
        vec.push_back(root->val);
        traverse(root->left, vec);
        traverse(root->right, vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
};