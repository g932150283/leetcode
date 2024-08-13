#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.

 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
*/
class Solution
{
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        traverse(root);
        return res;
    }

    int traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};