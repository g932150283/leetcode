#include <iostream>
#include <algorithm>

// 定义AVL节点结构
struct AvlNode {
    int data;
    AvlNode* lchild; // 左孩子
    AvlNode* rchild; // 右孩子
    int height; // 节点高度

    AvlNode(int val) : data(val), lchild(nullptr), rchild(nullptr), height(0) {}
};

// AVL树类
class AVLTree {
public:
    // 计算节点的高度
    static int height(AvlNode* T) {
        return (T == nullptr) ? -1 : T->height;
    }

    // 左旋转操作，用于左-左型情况
    static AvlNode* R_Rotate(AvlNode* K2) {
        AvlNode* K1 = K2->lchild;
        K2->lchild = K1->rchild;
        K1->rchild = K2;

        K2->height = std::max(height(K2->lchild), height(K2->rchild)) + 1;
        K1->height = std::max(height(K1->lchild), height(K1->rchild)) + 1;

        return K1;
    }

    // 右旋转操作，用于右-右型情况
    static AvlNode* L_Rotate(AvlNode* K2) {
        AvlNode* K1 = K2->rchild;
        K2->rchild = K1->lchild;
        K1->lchild = K2;

        K2->height = std::max(height(K2->lchild), height(K2->rchild)) + 1;
        K1->height = std::max(height(K1->lchild), height(K1->rchild)) + 1;

        return K1;
    }

    // 左-右型旋转操作
    static AvlNode* R_L_Rotate(AvlNode* K3) {
        K3->lchild = R_Rotate(K3->lchild);
        return L_Rotate(K3);
    }

    // 右-左型旋转操作
    static AvlNode* L_R_Rotate(AvlNode* K3) {
        K3->rchild = L_Rotate(K3->rchild);
        return R_Rotate(K3);
    }

    // 插入操作
    static AvlNode* insert(int data, AvlNode* T) {
        if (T == nullptr) {
            T = new AvlNode(data);
        } else if (data < T->data) {
            T->lchild = insert(data, T->lchild);
            if (height(T->lchild) - height(T->rchild) == 2) {
                if (data < T->lchild->data) {
                    T = R_Rotate(T);
                } else {
                    T = R_L_Rotate(T);
                }
            }
        } else if (data > T->data) {
            T->rchild = insert(data, T->rchild);
            if (height(T->rchild) - height(T->lchild) == 2) {
                if (data > T->rchild->data) {
                    T = L_Rotate(T);
                } else {
                    T = L_R_Rotate(T);
                }
            }
        }

        T->height = std::max(height(T->lchild), height(T->rchild)) + 1;
        return T;
    }
};

// 用于在终端中输出AVL树的结构
void printAVLTree(AvlNode* root, int level = 0) {
    if (root != nullptr) {
        printAVLTree(root->rchild, level + 1);
        for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << root->data << std::endl;
        printAVLTree(root->lchild, level + 1);
    }
}



// 测试方法
void testAVLTree() {
    AVLTree tree;
    AvlNode* root = nullptr;

    // 插入元素并执行旋转操作
    root = AVLTree::insert(3, root);
    std::cout << "root = AVLTree::insert(3, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(2, root);
    std::cout << "root = AVLTree::insert(2, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(1, root);
    std::cout << "root = AVLTree::insert(1, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(4, root);
    std::cout << "root = AVLTree::insert(4, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(5, root);
    std::cout << "root = AVLTree::insert(5, root);:" << std::endl;
    printAVLTree(root);

    // 添加更多测试用例
    root = AVLTree::insert(6, root); // 左-左型，右旋转
    std::cout << "root = AVLTree::insert(6, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(7, root); // 左-右型，左旋再右旋
    std::cout << "root = AVLTree::insert(7, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(8, root); // 右-右型，左旋转
    std::cout << "root = AVLTree::insert(8, root);:" << std::endl;
    printAVLTree(root);
    root = AVLTree::insert(9, root); // 右-左型，右旋再左旋
    std::cout << "root = AVLTree::insert(9, root);:" << std::endl;
    printAVLTree(root);

    // 显示最终的AVL树
    std::cout << "最终的AVL树:" << std::endl;
    // 添加用于可视化显示AVL树的代码
    printAVLTree(root);

}

int main() {
    testAVLTree();
    return 0;
}
