#include<bits/stdc++.h>

using namespace std;


/**

 */

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param l1 ListNode类 链表1
     * @param l2 ListNode类 链表2
     * @return ListNode类
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // write code here
        vector<int> res;
        // ListNode* head = new ListNode(0);
        while (l1 && l2)
        {
            res.push_back(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
            /* code */
        }
        while (l1)
        {
            res.push_back(l1->val);
            l1 = l1->next;
            /* code */
        }
        while (l2)
        {
            res.push_back(l2->val);
            l2 = l2->next;
            /* code */
        }

        // 多一位做缓冲
        res.push_back(0);
        for(int i = 0; i < res.size(); i++){
            if(res[i] >= 10){
                res[i + 1] = res[i + 1] + 1;
                res[i] = res[i] - 10;
            }
        }
        if(res[res.size() - 1] == 0){
            res.pop_back();
        }
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        for(int r : res){
            cur->next = new ListNode(r);
            cur = cur->next;
        }
        return head->next;
    }
        
        
    
};