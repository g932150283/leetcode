class Solution {
    unordered_map<int, int> inIndex;
    TreeNode* build(vector<int>& preorder, int lp, int rp,
                    vector<int>& inorder, int li, int ri){
        if(lp > rp){
            return nullptr;
        }
        int m_val = preorder[lp];
        int index = inIndex[m_val];
        int len = index - li;
        TreeNode* root = new TreeNode(m_val);
        root->left = build(preorder, lp + 1, lp + len, inorder, li, index - 1);
        root->right = build(preorder, lp + len + 1, rp, inorder, index + 1, ri);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        int i = 0;
        for(int num : inorder){
            inIndex[num] = i++;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }
};

// class Solution {
// public:
//     // 存储 inorder 中值到索引的映射
//     unordered_map<int, int> valToIndex;

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         for (int i = 0; i < inorder.size(); i++) {
//             valToIndex[inorder[i]] = i;
//         }
//         return build(preorder, 0, preorder.size() - 1,
//                     inorder, 0, inorder.size() - 1);
//     }

//     // build 函数的定义：
//     // 若前序遍历数组为 preorder[preStart..preEnd]，
//     // 中序遍历数组为 inorder[inStart..inEnd]，
//     // 构造二叉树，返回该二叉树的根节点
//     TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
//                     vector<int>& inorder, int inStart, int inEnd) {

//         if (preStart > preEnd) {
//             return NULL;
//         }

//         // root 节点对应的值就是前序遍历数组的第一个元素
//         int rootVal = preorder[preStart];
//         // rootVal 在中序遍历数组中的索引
//         int index = valToIndex[rootVal];

//         int leftSize = index - inStart;

//         // 先构造出当前根节点
//         TreeNode* root = new TreeNode(rootVal);
//         // 递归构造左右子树
//         root->left = build(preorder, preStart + 1, preStart + leftSize,
//                         inorder, inStart, index - 1);

//         root->right = build(preorder, preStart + leftSize + 1, preEnd,
//                         inorder, index + 1, inEnd);
//         return root;
//     }
// };