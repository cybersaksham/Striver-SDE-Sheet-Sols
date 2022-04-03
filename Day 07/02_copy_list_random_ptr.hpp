/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        
        Node *newHead = NULL;
        Node *tmp = head;
        
        while(tmp != NULL) {
            Node *tmp2 = new Node(tmp->val);
            if(newHead == NULL) newHead = tmp2;
            m[tmp] = tmp2;
            tmp = tmp->next;
        }
        
        unordered_map<Node *, Node *>::iterator it;
        for(it=m.begin(); it!=m.end(); it++) {
            if(it->first->next != NULL) it->second->next = m[it->first->next];
            else it->second->next = NULL;
            if(it->first->random != NULL) it->second->random = m[it->first->random];
            else it->second->random = NULL;
        }
        
        return newHead;
    }
};