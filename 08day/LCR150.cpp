/**
 * Definition for a binary tree node.

 */

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // 二维数组
        if (!root) {
            return res;
        }
        // 获取队列大小k
        // 循环获取k个结点，这k个结点为其中一层结点个数

        queue<TreeNode*> q{{root}};
        while (!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++){
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            res.push_back(level);
        }
        return res;
        // queue<TreeNode*> q{{root}};
        // while (!q.empty()) {
        //     int n = q.size();
        //     vector<int> level;
        //     for (int i = 0; i < n; ++i) {
        //         auto t = q.front();
        //         q.pop();
        //         level.push_back(t->val);
        //         if (t->left) {
        //             q.push(t->left);
        //         }
        //         if (t->right) {
        //             q.push(t->right);
        //         }
        //     }
        //     res.push_back(level);
        // }
        // return res;
    }
};

TreeNode *vectorToTree(vector<int> list) {
    TreeNode *root = new TreeNode(list[0]);
    queue<TreeNode *> que;
    que.emplace(root);
    int i = 1;
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        if (list[i] != INT_MAX) {
            node->left = new TreeNode(list[i]);
            que.emplace(node->left);
        }
        i++;
        if (list[i] != INT_MAX) {
            node->right = new TreeNode(list[i]);
            que.emplace(node->right);
        }
        i++;
    }
    return root;
}

class PrintUtil {
public:
    static void printVectorMatrix(const vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    // ======= Test Case =======
    // TreeNode *root = vectorToTree(vector<int>{3, 9, 20, INT_MAX, INT_MAX, 15, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    TreeNode *root = vectorToTree(vector<int>{8, 17, 21, 18, INT_MAX, INT_MAX, 6, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    
    // ====== Driver Code ======
    Solution *slt = new Solution();
    vector<vector<int>> res = slt->levelOrder(root);
    PrintUtil::printVectorMatrix(res);

    return 0;
}