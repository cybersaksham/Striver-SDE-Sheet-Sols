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
    int getLength(ListNode *head) {
        if(head == NULL) return 0;
        return 1 + this->getLength(head->next);
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = this->getLength(head);
        
        if(n == 0 || n == 1) return head;
        
        k = k % n;
        
        ListNode *tmp = head;
        for(int i=0; i<n-k-1; i++) tmp = tmp->next;
        
        ListNode *tmp2 = tmp->next;
        tmp->next = NULL;
        
        ListNode *tmp3 = tmp2;
        while(tmp3 != NULL && tmp3->next != NULL) tmp3 = tmp3->next;
        
        if(tmp3 == NULL) return head;
        else {
            tmp3->next = head;
            return tmp2;
        }
    }
};