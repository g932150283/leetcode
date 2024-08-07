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
// 快慢指针
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast || fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
            /* code */
        }
        return false;
        
        
    }
};