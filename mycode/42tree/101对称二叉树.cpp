
#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x),  left(nullptr), right(nullptr) {}
        /* data */
};


class Solution {
public:

    bool leftright(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr){
            return false;
        }else if(left != nullptr && right == nullptr){
            return false;
        }else if(left == nullptr && right == nullptr){
            return true;
        }else if(left->val != right->val){
            return false;
        }

        bool out = leftright(left->left, right->right);
        bool in = leftright(left->right, right->left);
        bool issymmetric = out && in;
        return issymmetric;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return leftright(root->left, root->right);
    }
};