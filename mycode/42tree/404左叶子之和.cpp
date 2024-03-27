
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }

        int left = sumOfLeftLeaves(root->left);
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
            left = root->left->val;
        }
        int right = sumOfLeftLeaves(root->right);
        int sum = right + left;
        return sum;

    }
};