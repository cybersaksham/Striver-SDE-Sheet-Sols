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
    ListNode *reverseNodes(ListNode *head, ListNode *tail) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        
        while(curr != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmp = head;
        ListNode *tmpHead = NULL;
        ListNode *tmpHead2 = NULL;
        ListNode *prev = NULL;
        
        while(tmp != NULL) {
            tmpHead2 = tmp;
            int i = 0;
            for(i=0; i<k ; i++) {
                if(tmp) tmp = tmp->next;
                else break;
            }
            
            if(i == k) {
                ListNode *tmp2 = this->reverseNodes(tmpHead2, tmp);
                if(prev) prev->next = tmp2;
                if(tmpHead == NULL) tmpHead = tmp2;
                prev = tmpHead2;
            }
            else if(prev) prev->next = tmpHead2;
        }
        
        return tmpHead;
    }
};