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
    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *cur, *nxt, *pre;
        cur = a;
        nxt = a;
        pre = nullptr;
        while (cur != b)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            /* code */
        }
        return pre;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a, *b;
        a = head;
        b = head;
        for(int i = 0; i < k; i++){
            if(b == nullptr){
                return head;
            }
            b = b->next;
        }
        ListNode *newNode = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newNode;
    }
};