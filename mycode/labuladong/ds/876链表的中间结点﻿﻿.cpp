class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
            /* code */
        }
        return slow;
        
    }
};