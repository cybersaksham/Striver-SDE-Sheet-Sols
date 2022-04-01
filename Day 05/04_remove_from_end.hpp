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
    int removeByInd(ListNode *head, int n) {
        if(head == NULL) return 0;
        int ind = this->removeByInd(head->next, n);
        if(ind == n) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
        return ind + 1;
    }
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ind = this->removeByInd(head, n);
        if(ind == n) {
            ListNode *tmp = head->next;
            delete head;
            return tmp;
        }
        return head;
    }
};