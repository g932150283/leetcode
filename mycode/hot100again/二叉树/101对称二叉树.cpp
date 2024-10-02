class Solution {
    bool isS(TreeNode* r1, TreeNode* r2){
        if(r1 == nullptr && r2 == nullptr){
            return true;
        }else if(r1 == nullptr){
            return false;
        }else if(r2 == nullptr){
            return false;
        }else if(r1->val != r2->val){
            return false;
        }else{
            return (isS(r1->left, r2->right) && isS(r2->left, r1->right));
        }



    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isS(root->left, root->right);
    }
};