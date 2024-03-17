#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* l) : val(x), next(l) {} 
    /* data */
};



class Solution
{
private:
    /* data */
public:
    ListNode* removeElement(ListNode* head, int val){
        // // 删除头节点
        // while (head != nullptr && head->val == val)
        // {
        //     ListNode* tmp = head;
        //     head = head->next;
        //     delete tmp;
        //     /* code */
        // }

        // // 删除非头节点
        // ListNode* cur = head;
        // while (cur != nullptr && cur->next != nullptr)
        // {
        //     if(cur->next->val == val){
        //         ListNode* tmp = cur->next;
        //         cur->next = cur->next->next;
        //         delete tmp;
        //     }else{
        //         cur = cur->next;
        //     }
        //     /* code */
        // }

        // return head;

        // 带虚拟头
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while (cur->next != nullptr)
        {
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        
        return dummyHead->next;
        
        
        
    }
};
