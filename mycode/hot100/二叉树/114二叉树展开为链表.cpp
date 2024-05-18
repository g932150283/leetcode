#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    vector<TreeNode*> res;
    void preorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        res.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
public:
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode* cur = root;
        for(auto node : res){
            cur->left = nullptr;
            cur->right = node;
            cur = cur->right;
        }
    }
};