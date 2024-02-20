/**
 * Definition for a binary tree node.

 */
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
public:
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        // 中序遍历转换为map
        for(int i = 0; i < inorder.size(); i++)
            hmap[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }

    vector<int> preorder;
    unordered_map<int, int> hmap;
    /**
     * @brief 递归建立二叉树
     * 
     * @param root 根节点在前序遍历中的位置
     * @param left 中序遍历左边界
     * @param right 中序遍历右边界
     * @return TreeNode* 
     */
    TreeNode* recur(int root, int left, int right) { 
        if(left > right){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[root]);  // 建立根结点，前序的位置
        int i = hmap[preorder[root]];                   // 获取根节点在中序遍历中的位置
        node->left = recur(root + 1, left, i - 1);
        node->right = recur(root + 1 + i - left, i + 1, right);
        return node;
    }
    // 明天继续看

};