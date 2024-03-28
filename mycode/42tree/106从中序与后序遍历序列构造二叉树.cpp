#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

    /* data */
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return;
        }
        TreeNode* root = new TreeNode(postorder.back());

        if(postorder.size() == 1){
            return root;
        }

        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if(inorder[delimiterIndex] == root->val){
                break;
            }
        }

        vector<int> leftinorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightinorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());

        root->left = buildTree(leftinorder, leftpostorder);
        root->right = buildTree(rightinorder, rightpostorder);

        return root;
    }
};