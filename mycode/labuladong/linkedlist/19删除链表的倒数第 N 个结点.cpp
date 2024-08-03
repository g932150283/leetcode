/**
 * Definition for singly-linked list.

 */
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        // 倒数n+1
        ListNode* pre = &dummy;
        ListNode* h = &dummy;
        for(int i = 0; i < n + 1; i++){
            h = h->next;
        }
        while (h)
        {
            h = h->next;
            pre = pre->next;
            /* code */
        }
        pre->next = pre->next->next;
        return dummy.next;
        
        
    }
};