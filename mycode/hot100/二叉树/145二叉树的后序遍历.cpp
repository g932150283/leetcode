
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.

 */

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
    vector<int> postorderTraversal(TreeNode* root) {
        // stack<TreeNode*> st;
        // vector<int> res;
        // if(root == nullptr){
        //     return res;
        // }
        // st.push(root);
        // while (!st.empty())
        // {
        //     TreeNode* node = st.top();
        //     st.pop();
        //     res.push_back(node->val);
        //     if(node->left){
        //         st.push(node->left);
        //     }
        //     if(node->right){
        //         st.push(node->right);
        //     }
        //     /* code */
        // }
        // reverse(res.begin(), res.end());
        // return res;


        vector<int> res;
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode* node = st.top();
            if(node){
                // 后续 左右中，栈中取反，中右左
                st.pop();
                st.push(node);
                st.push(nullptr);
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
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