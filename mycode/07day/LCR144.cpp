/**
 * Definition for a binary tree node.
 * 
 */
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return root;
        }

        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);

        root->left = right;
        root->right = left;

        return root;

    }
};

TreeNode *vectorToTree(vector<int> list) {
    TreeNode *root = new TreeNode(list[0]);
    queue<TreeNode *> que;
    que.emplace(root);
    int i = 1;
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        if (list[i] != INT_MAX) {
            node->left = new TreeNode(list[i]);
            que.emplace(node->left);
        }
        i++;
        if (list[i] != INT_MAX) {
            node->right = new TreeNode(list[i]);
            que.emplace(node->right);
        }
        i++;
    }
    return root;
}


void printTreeLevelOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        cout << endl;
    }
}


int main(){

    TreeNode *root = vectorToTree(
        vector<int>{4, 2, 7, 1, 3, 6, 9, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    Solution *slt = new Solution();
    TreeNode *res = slt->mirrorTree(root);
    printTreeLevelOrder(res);

    
    return 0;  
}