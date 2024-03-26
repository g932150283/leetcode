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
public:
    int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getHeight(root->left);
        if(left == -1){
            return -1;
        }
        int right = getHeight(root->right);
        if(right == -1){
            return -1;
        }

        if(abs(left - right) > 1){
            return -1;
        }else{
            return 1 + max(left, right);
        }
    }

    bool isBalanced(TreeNode* root) {
        int dep = getHeight(root);
        if(dep == -1){
            return false;
        }
        return true;
    }
};