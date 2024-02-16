/**
 * Definition for a binary tree node.

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
    // 1 先判断B是不是以A结点为根节点的一个子树
    //      否 判断B是否是A左右子树的一个子结点
    // 2 issubtree(a, b) b是否以a为根节点的子树
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;

        if(!A && !B){
            if(A->val == B->val){
                result = issubTree(A, B);
            }
            if(!result){
                result = isSubStructure(A->left, B);
            }

            if(!result){
                result = isSubStructure(A->right, B);
            }
        }
        return result;
    }

    bool issubTree(TreeNode* A, TreeNode* B){
        if(!B){
            return true;
        }
        if(!A){
            return false;
        }
        if(A->val != B->val){
            return false;
        }

        return issubTree(A->left, B->left) && issubTree(A->right, B->right);
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
        vector<int>{4, 2, 3, 4, 5, 6, 7, 8, 9, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    TreeNode *B = vectorToTree(
        vector<int>{4, 8, 9, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    Solution *slt = new Solution();
    auto res = slt->isSubStructure(root, B);
    // printTreeLevelOrder(res);
    cout << res << endl;
    
    return 0;  
}