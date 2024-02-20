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

void printBT(const string& prefix, const TreeNode* node, bool isLeft) {
    if (node != nullptr) {
        cout << prefix;

        cout << (isLeft ? "├──L: " : "└──R: ");

        // print the value of the node
        cout << node->val << endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printTree(const TreeNode* node) {
    printBT("", node, false);    
}


int main() {
    // ======= Test Case =======
    // vector<int> preorder = {3, 9, 20, 15, 7};
    // vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};
    // ====== Driver Code ======
    Solution *slt = new Solution();
    TreeNode *res = slt->deduceTree(preorder, inorder);
    printTree(res);

    return 0;
}