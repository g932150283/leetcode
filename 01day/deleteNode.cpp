#include "../include/include.hpp"
// ===== Solution Code =====
class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        // 如果空，返回
        if(head == NULL){
            return;
        }
        int flag = 0;
        while (head->val != val)
        {
            head = head->next;
            if(head->next == NULL){
                flag = 1;
                //到底了
            }
        }

        if(flag == 0){
            head
        }

        return head;
        
        {
            head = head->next;
            /* code */
        }

        if(head->next != NULL)
        
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
