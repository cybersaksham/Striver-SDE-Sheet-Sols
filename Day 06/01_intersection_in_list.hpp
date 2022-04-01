/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        
        while(ptr1 != NULL) {
            ptr1->val *= -1;
            ptr1 = ptr1->next;
        }
        
        int k = -1;
        while(ptr2 != NULL) {
            k++;
            if(ptr2->val < 0) break;
            ptr2 = ptr2->next;
        }
        if(ptr2 == NULL && k >= 0) k++;
        
        ptr1 = headA;
        while(ptr1 != NULL) {
            ptr1->val *= -1;
            ptr1 = ptr1->next;
        }
        
        ptr2 = headB;
        for(int i=0; i<k; i++) ptr2 = ptr2->next;
        
        return ptr2;
    }
};