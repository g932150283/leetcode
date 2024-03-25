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
    int countNodes(TreeNode* root) {
    if(root == nullptr){
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left+right+1;
    }
};