#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    // ListNode* left;
    // ListNode* right;
    // bool res = true;
    ListNode* reverse(ListNode* a, ListNode* b){
        
    }
public:

    bool isPalindrome(ListNode* head) {
        // left = head;
        // traverse(head);
        // return res;
    }
    // void traverse(ListNode* node){
    //     if(node == nullptr){
    //         return;
    //     }
    //     traverse(node->next);
    //     if(node->val != left->val){
    //         res = false;
    //     }
    //     left = left->next;
    // }

};

int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(2);
    ListNode* l4 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution* s = new Solution();
    s->isPalindrome(l1);

    return 0;
}