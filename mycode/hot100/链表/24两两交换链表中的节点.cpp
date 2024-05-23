#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    /* data */
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if(head == nullptr){
        //     return head;
        // }
        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* cur = dummy;
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while (slow && fast)
        // {
        //     cur->next = slow->next;
        //     slow->next = fast->next;
        //     fast->next = slow;
        //     cur = slow;
        //     slow = slow->next;
        //     if(slow == nullptr){
        //         break;
        //     }
        //     fast = slow->next;
        //     /* code */
        // }
        // return dummy->next;

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* node3 = node2->next;

        node1->next = swapPairs(node3);
        node2->next = node1;

        return node2;

        
    }
};