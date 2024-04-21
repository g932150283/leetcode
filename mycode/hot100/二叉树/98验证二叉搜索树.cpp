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
    bool isValid(TreeNode* root, long long lower, long long upper){
        if(root == nullptr){
            return true;
        }
        if(root->val <= lower || root->val >= upper){
            return false;
        }
        return isValid(root->right, root->val, upper) && isValid(root->left, lower, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);

    
    }
};