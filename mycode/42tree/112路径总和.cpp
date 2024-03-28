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
    vector<int> res;
    int path;
    void backtracking(TreeNode* root){
        path += root->val;

        if(root->left == nullptr && root->right == nullptr){
            res.push_back(path);
            return;
        }

        if(root->left){
            backtracking(root->left);
            path -= root->left->val;
        }

        if(root->right){
            backtracking(root->right);
            path -= root->right->val;
        }
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        backtracking(root);
        if(find(res.begin(), res.end(), targetSum) == res.end()){
            return false;
        }
        return true;
    }
};


// TreeNode* vectorToTree(vector<int> v){
//     TreeNode* root = new TreeNode(v[0]);

// }

int main(){

    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode();
    TreeNode* n6 = new TreeNode(13);
    TreeNode* n7 = new TreeNode(4);
    TreeNode* n8 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(2);
    TreeNode* n10 = new TreeNode();
    TreeNode* n11 = new TreeNode();
    TreeNode* n12 = new TreeNode();
    TreeNode* n13 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n4->left = n8;
    n4->right = n9;
    n3->left = n6;
    n3->right = n7;
    n7->right = n13;

    Solution* s = new Solution();
    s->hasPathSum(n1, 22);

}