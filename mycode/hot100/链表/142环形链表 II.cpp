#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (true)
        {
            if(fast == nullptr || fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
            /* code */
        }
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
            /* code */
        }
        return fast;
        
        
    }
};