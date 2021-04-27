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
        Node *nhead=NULL;
        Node* curr;
        Node *t=head;
        unordered_map<Node*,Node*> m;
        while(t){
            
            if(nhead==NULL){
                nhead=new Node(t->val);
                curr=nhead;
            }
            else{
                curr->next=new Node(t->val);
                curr=curr->next;
            }
            m[t]=curr;
            t=t->next;
        }
        t=head;
        curr=nhead;
        while(t){
            curr->random=m[t->random];
            t=t->next;
            curr=curr->next;
        }
        return nhead;
    }
};
