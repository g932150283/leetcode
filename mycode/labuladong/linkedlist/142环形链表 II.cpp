/**
 * Definition for singly-linked list.

 */

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while (slow != head)
                {
                    head = head->next;
                    slow = slow->next;
                    /* code */
                }
                return slow;
                
            }
            /* code */
        }
        return nullptr;
    }
};

int main(){
    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(-4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution* s = new Solution();
    s->detectCycle(l1);

    return 0;
}