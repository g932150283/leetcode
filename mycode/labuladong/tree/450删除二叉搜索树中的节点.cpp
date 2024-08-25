
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
    TreeNode* getMin(TreeNode* root){
        while (root->left != nullptr)
        {
            root = root->left;
            /* code */
        }
        return root;
        
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == key){
            // delete
            if(root->left == nullptr){
                return root->right;
            }
            if(root->right == nullptr){
                return root->left;
            }
            TreeNode* minNode = getMin(root->right);
            root->right = deleteNode(root->right, minNode->val);
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};