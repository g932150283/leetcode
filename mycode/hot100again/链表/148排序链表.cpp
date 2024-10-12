class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {   
            slow = slow->next;
            fast = fast->next->next;
            /* code */
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        ListNode* h = new ListNode();
        ListNode* res = h;
        while (left != nullptr && right != nullptr)
        {
            if(left->val < right->val){
                h->next = left;
                left = left->next;
            }else{
                h->next = right;
                right = right->next;
            }
            h = h->next;
            /* code */
        }
        if(left){
            h->next = left;
        }
        if(right){
            h->next = right;
        }
        return res->next;
         
        
    }
};