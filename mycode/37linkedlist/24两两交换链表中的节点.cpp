
#include<bits/stdc++.h>

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* tmp = dummy;
        ListNode* cur = tmp->next;
        ListNode* pre = cur->next;
        while (cur && pre)
        {
            tmp->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            tmp = cur;
            if(tmp->next == nullptr){
                break;
            }
            cur = tmp->next;
            pre = cur->next;
            /* code */
        }

        return dummy->next;
        
    }
};