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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode* node = st.top();
            if(node){
                st.pop();
                // preorder  m l r reverse r l m
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
            /* code */
        }
        return res;
        
    }

};