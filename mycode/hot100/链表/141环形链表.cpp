#include <bits/stdc++.h>

using namespace std;

/**

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr)
        {
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
            if(fast == slow){
                return true;
            }
            slow = slow->next;
            /* code */
        }
        return false;
        
    }
};