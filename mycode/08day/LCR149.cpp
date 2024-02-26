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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        // 添加root到queue，queue不为空时，队首元素加入结果集合，并出队，之后将左右子树添加到队列中
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res.push_back(t->val);
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        return res;
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
    static void printVector(const std::vector<int>& vec) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i != vec.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    // ======= Test Case =======
    // TreeNode *root = vectorToTree(vector<int>{3, 9, 20, INT_MAX, INT_MAX, 15, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    TreeNode *root = vectorToTree(vector<int>{8, 17, 21, 18, INT_MAX, INT_MAX, 6, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    // ====== Driver Code ======
    Solution *slt = new Solution();
    vector<int> res = slt->levelOrder(root);
    PrintUtil::printVector(res);

    return 0;
}