#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr) {}
};

int res = 0;

TreeNode* backtracking(string& preoder, string& inorder, unordered_map<char, int>& indexMap){
    if(preoder.size() == 0){
        return nullptr;
    }
    
    char c = preoder[0];
    TreeNode* root = new TreeNode(c);

    int orderIndex = 0;
    for(int i = 0; i < preoder.size(); i++){
        if(inorder[i] == c){
            orderIndex = i;
            break;
        }
    }
    string leftInoder = inorder.substr(0, orderIndex);
    string rightInofer = inorder.substr(orderIndex + 1, inorder.size());

    char ch = rightInofer[0];
    int preoderIndex = 0;
    for(int i = 1; i < preoder.size(); i++){
        if(preoder[i] == ch){
            preoderIndex = i;
            break;
        }
    }

    string leftPreoder = preoder.substr(1, preoderIndex - 1);
    string rightPreoder = preoder.substr(preoderIndex, inorder.size());

    root->left = backtracking(leftPreoder, leftInoder, indexMap);
    root->right = backtracking(rightPreoder, rightInofer, indexMap);

    return root;



}

int getHeight(TreeNode* root)
{
    if(root == nullptr){
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int res = max(left, right) + 1;
    return res;
}


int main(){
    int n;
    while (cin >> n)
    {
        string preorder, inorder;
        cin >> preorder >> inorder;
        /* code */
        unordered_map<char, int> indexMap;
        for(int i = 0; i < preorder.size(); i++){
            indexMap[preorder[i]] = i;
        }
        TreeNode* root = backtracking(preorder, inorder, indexMap);
        int height = getHeight(root);
        cout << height << endl;
    }

    
    return 0;
    
}