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
    bool isValid(TreeNode* root, long l, long r){
        if(root == nullptr){
            return true;
        }
        if(root->val >= r || root->val <= l){
            return false;
        }
        return isValid(root->left, l, root->val) && isValid(root->right, root->val, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);

    
    }
};