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
public:

    int getDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(root->left == nullptr && root->right != nullptr){
            return 1 + right; 
        }
        if(root->right == nullptr && root->left != nullptr){
            return 1 + left; 
        }

        return 1 + min(left, right);
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};