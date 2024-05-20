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
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
        if(l1 > r1 || l2 > r2){
            return nullptr;
        }
        int mid = preorder[l1];
        TreeNode* root = new TreeNode(mid);
        int in = 0;
        for(int i = 0; i < preorder.size(); i++){
            if(inorder[i] == mid){
                in = i;
                break;
            }
        }
        int pre = in - l2;
        root->left = buildTree1(preorder, inorder, l1 + 1, l1 + pre, l2, in - 1);
        root->right = buildTree1(preorder, inorder, l1 + pre + 1, r1, in + 1, r2);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree1(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};