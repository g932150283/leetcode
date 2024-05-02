#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    ListNode* recur(ListNode* cur, ListNode* pre){
        if(cur == nullptr){
            return pre;
        }
        ListNode* res = recur(cur->next, cur);
        // 然后呢
        // 倒反天罡
        cur->next = pre;
        return res;
    }

public:
    ListNode* reverseList(ListNode* head) {
        // if(head == nullptr){
        //     return nullptr;
        // }
        // if(head->next == nullptr){
        //     return head;
        // }
        // ListNode* cur = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return cur;

        //双指针
        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        // while (cur != nullptr)
        // {
        //     ListNode* tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        //     /* code */
        // }
        // return pre;
        return recur(head, nullptr);           // 调用递归并返回
        
    }
};

int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution* s = new Solution();
    s->reverseList(l1);

    return 0;
}