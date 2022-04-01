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
    ListNode *reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *newHead = this->reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow = this->reverseList(slow);
        ListNode *tmp = slow;
        
        while(slow != NULL) {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};