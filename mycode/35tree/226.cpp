
#include<bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
    /* data */
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        backtracking(root);
        return root;
    }

    void backtracking(TreeNode* root){
        if(root){
            TreeNode* node = root->left;
            root->left = root->right;
            root->right = node;
            backtracking(root->left);
            backtracking(root->right);
        }else{
            return;
        }
    }
};