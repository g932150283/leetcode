
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
    unordered_map<int, int> inIndex;
    TreeNode* build(vector<int>& preorder, int lp, int rp,
                    vector<int>& inorder, int li, int ri){
        if(lp > rp){
            return nullptr;
        }
        int m_val = preorder[lp];
        int index = inIndex[m_val];
        int len = index - lp;
        TreeNode* root = new TreeNode(m_val);
        root->left = build(preorder, lp + 1, lp + len, inorder, li, li + len);
        root->right = build(preorder, lp + len + 1, rp, inorder, li + len + 1, ri);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        int i = 0;
        for(int num : inorder){
            inIndex[num] = i++;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }
};