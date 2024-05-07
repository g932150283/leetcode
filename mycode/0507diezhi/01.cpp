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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            /* code */
        }
        return pre;
        
    }
};