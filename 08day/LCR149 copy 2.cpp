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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res.push_back(t->val);
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        return res;
    }
};

