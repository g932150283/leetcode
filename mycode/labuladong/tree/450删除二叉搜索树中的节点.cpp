
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
    TreeNode* deleteNode(TreeNode* root, int key) {
    if (root->val == key) {
        // 找到啦，进行删除
    } else if (root->val > key) {
        // 去左子树找
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        // 去右子树找
        root->right = deleteNode(root->right, key);
    }
    return root;
}
};