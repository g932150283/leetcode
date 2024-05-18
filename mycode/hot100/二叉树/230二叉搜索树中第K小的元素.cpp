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
    int num;
    int res;
    int flag = 0;
    void midp(TreeNode* root){
        if(root == nullptr || flag == 1){
            return;
        }
        midp(root->left);
        num--;
        if(num == 0){
            res = root->val;
            flag = 1;
            return;
        }
        midp(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        num = k;
        midp(root);
        return res;
    }
};