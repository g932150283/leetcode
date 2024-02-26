#include "../include/include.hpp"
// ===== Solution Code =====
class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        if(head->val == val){
            return head->next;
        }
        
        ListNode* p = head;
        while (p->next != nullptr && p->next->val != val){
            p = p->next;
        }

        if(p->next != nullptr){
            p->next = p->next->next;
        }

        return head;
    }
};

int main() {
    // ======= Test Case =======
    ListNode *head = vectorToLinkedList(vector<int>{4, 5, 1, 9});
    int val = 5;
    // ====== Driver Code ======
    Solution *slt = new Solution();
    ListNode *res = slt->deleteNode(head, val);
    PrintUtil::printLinkedList(res);

    return 0;
}
