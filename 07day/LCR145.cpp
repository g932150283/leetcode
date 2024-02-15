#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return true;
        }

        return f(root->left, root->right);
    }

    // ab是否为镜像二叉树
    bool f(TreeNode* A, TreeNode* B){
        if(!A && !B){
            return true;
        }
        if(!A || !B){
            return false;
        }
        if(A->val != B->val){
            return false;
        }

        return f(A->left, B->right) && f(A->right, B->left);
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
        vector<int>{4, 2, 2, 1, 2, 3, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    Solution *slt = new Solution();
    auto res = slt->isSymmetric(root);
    // printTreeLevelOrder(res);
    cout << res << endl;

    
    return 0;  
}