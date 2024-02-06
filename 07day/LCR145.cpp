#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return true;
        }

        return f(root->left, root->right);
    }

    // 判断B是不是以A阶段为根节点的子树
    bool f(TreeNode* A, TreeNode* B) {
        if (!A && !B) {
            return true;
        }

        if (!A || !B) {
            return false;
        }

        if (A->val != B->val) {
            return false;
        }

        return f(A->left, B->right) && f(A->right, B->left);
    }
};

