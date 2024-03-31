#include <bits/stdc++.h>
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        }else if(root->left == nullptr && (root->right != nullptr && root->val < root->right->val)){
            return true;
        }else if(root->right == nullptr && (root->left != nullptr && root->val > root->left->val)){
            return true;
        }else if(root->left != nullptr && root->left != nullptr && root->val > root->left->val && root->val < root->right->val){
            return true;
        }else{
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->left);
    }
};

int main(){
    TreeNode* r1 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(1);
    TreeNode* r3 = new TreeNode(3);
    r1->left = r2;
    r1->right = r3;

    Solution* s = new Solution();
    s->isValidBST(r1);
    return 0;
}