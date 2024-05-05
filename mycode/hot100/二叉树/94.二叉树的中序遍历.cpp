
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
    vector<int> inorderTraversal(TreeNode* root) {
        // stack<TreeNode*> st;
        // vector<int> res;
        // if(root == nullptr){
        //     return res;
        // } 
        // TreeNode* cur = root;
        // while (cur || !st.empty())
        // {
        //     if(cur){
        //         st.push(cur);
        //         cur = cur->left;
        //     }else{
        //         cur = st.top();
        //         st.pop();
        //         res.push_back(cur->val);
        //         cur = cur->right;
        //     }
        //     /* code */
        // }
        // return res;

        vector<int> res;
        stack<TreeNode*> st;
        if(root == nullptr){
            return res;
        }else{
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode* node = st.top();
            if(node){
                st.pop();
                if(node->right){
                    st.push(node->right);
                }

                st.push(node);
                st.push(nullptr);

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