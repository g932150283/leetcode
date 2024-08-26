
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
    int countNodes(TreeNode* root) {
        TreeNode* l = root, *r = root;
        int hl = 0, hr = 0;
        while (l != nullptr)
        {
            l = l->left;
            hl++;
            /* code */
        }
        while (r != nullptr)
        {
            r = r->right;
            hr++;
            /* code */
        }
        if(hr == hl){
            return pow(hr, 2) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
};