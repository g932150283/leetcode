#include<bits/stdc++.h>

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
    int getdepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = getdepth(root->left);
        int r = getdepth(root->right);
        res = max(l + r, res);
        return max(l, r) + 1;
    }
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getdepth(root);
        return res;

    }
};