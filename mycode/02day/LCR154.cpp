#include<bits/stdc++.h>
#include "../include/include.hpp"
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }

        // 复制
        Node* cur = head;
        while (cur != nullptr){
            Node* next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }      

        // random
        cur = head;
        while (cur != nullptr){
            Node* curNew = cur->next;
            curNew->random = cur->random ? cur->random->next : nullptr;
            // 空指针
            // cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        // 拆分
        Node* headNew = head->next;
        cur = head;
        Node* curNew = head->next;
        while (cur != nullptr){
            cur->next = cur->next->next;
            // 已经移动了
            cur = cur->next;
            curNew->next = cur ? cur->next : nullptr;
            curNew = curNew->next;
        }

        return headNew;
        
    }
};


int main(){
        // ======= Test Case =======
    vector<int> nodesVal{7, 13, 11, 10, 1};
    vector<int> nodesRandom{INT_MAX, 0, 4, 2, 0}; // Represent the 'null' Node with 'INT_MAX'
    // Construct nodes
    vector<Node *> nodeList;
    for (int val : nodesVal) {
        nodeList.push_back(new Node(val));
    }
    // Build next reference
    for (int i = 0; i < nodesVal.size() - 1; i++) {
        nodeList[i]->next = nodeList[i + 1];
    }
    // Build random reference
    for (int i = 0; i < nodesVal.size(); i++) {
        if (nodesRandom[i] != INT_MAX)
            // 位置
            nodeList[i]->random = nodeList[nodesRandom[i]];
    }
    // Get the head of the linked list
    Node *head = nodeList[0];

    // ====== Driver Code ======
    Solution *slt = new Solution();
    Node *res = slt->copyRandomList(head);
    // Print the copied linked list
    vector<Node *> nodeListNew;
    while (res != nullptr) {
        nodeListNew.push_back(res);
        res = res->next;
    }
    // 创建一个二维 vector 用于存储复制后的链表信息，每行包含两个元素（节点值和 random 指针指向的节点在新链表中的位置）
    vector<vector<int>> printArr(nodeListNew.size(), vector<int>(2));
    for (int i = 0; i < nodeListNew.size(); i++) {
        // 获取当前节点
        Node *node = nodeListNew[i];
        // 将当前节点的值存储到 printArr 的第一个元素
        printArr[i][0] = node->val;
        // 使用 PrintUtil::vecFind 查找 random 指针指向的节点在新链表中的位置，并将其存储到 printArr 的第二个元素
        printArr[i][1] = PrintUtil::vecFind(nodeListNew, node->random);
    }
    // 使用 PrintUtil::printVectorMatrix 打印存储链表信息的二维 vector
    PrintUtil::printVectorMatrix(printArr);

    return 0;
    return 0;
}