/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(l1 == NULL && l2 == NULL) {
            if(carry == 0) return NULL;
            ListNode *tmp = new ListNode(carry);
            return tmp;
        }
        if(l1 == NULL) {
            ListNode *tmp = new ListNode(carry);
            return this->addTwoNumbers(tmp, l2);
        }
        if(l2 == NULL) {
            ListNode *tmp = new ListNode(carry);
            return this->addTwoNumbers(tmp, l1);
        }
        
        int n = l1->val + l2->val + carry;
        ListNode *tmp = new ListNode(n % 10, this->addTwoNumbers(l1->next, l2->next, n / 10));
        
        return tmp;
    }
};