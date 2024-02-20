/**
 * Definition for a binary tree node.

 */

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
    int cnt;
    int res;
    int findTargetNode(TreeNode* root, int cnt) {
        this->cnt = cnt;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        dfs(root->right);
        // 找到了直接返回
        if(cnt == 0){
            return;
        }
        cnt--;
        if(cnt == 0){
            res = root->val;
            return;
        }
        dfs(root->left);
    }
};

TreeNode *vectorToTree(vector<int> list){
    TreeNode *root = new TreeNode(list[0]);
    queue<TreeNode *> q;
    q.emplace(root);
    // push() 先产生一个副本，然后将该副本移动到容器中；emplace()直接在容器尾构造。
    // 所以使用emplace()可以避免push()产生的额外的复制或移动操作。
    int i = 1;
    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(list[i] != INT_MAX){
            node->left = new TreeNode(list[i]);
            q.emplace(node->left);
        }
        i++;
        if(list[i] != INT_MAX){
            node->right = new TreeNode(list[i]);
            q.emplace(node->right);
        }
        i++;
    }
    return root;
}

int main(){

    vector<int> v = {7, 3, 9, 1, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    TreeNode *root = vectorToTree(v);
    Solution s;
    cout << s.findTargetNode(root, 2) << endl;
    return 0;
}