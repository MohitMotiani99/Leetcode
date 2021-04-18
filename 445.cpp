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
    ListNode* reverse(ListNode *head){
        if(head==NULL)
            return NULL;
        ListNode *p=NULL,*curr=head,*next;
        while(curr){
            next=curr->next;
            curr->next=p;
            
            p=curr;
            curr=next;
        }
        return p;
    }
    ListNode* addNum(ListNode* l1, ListNode* l2) {
    int c=0;
    ListNode *head=NULL;

    ListNode* t1=l1,*t2=l2,*t3=NULL;
    while(t1 && t2){
        int x=t1->val;
        int y=t2->val;

        ListNode *temp=new ListNode((x+y+c)%10);
        c=(x+y+c)/10;

        if(head==NULL)
        {
            head=temp;
            t3=head;
        }
        else{
            t3->next=temp;
            t3=t3->next;
        }

        t1=t1->next;
        t2=t2->next;
    }
    while(t1){
        int x=t1->val;

        ListNode *temp=new ListNode((x+c)%10);
        c=(x+c)/10;

        if(head==NULL)
        {
            head=temp;
            t3=head;
        }
        else{
            t3->next=temp;
            t3=t3->next;
        }

        t1=t1->next;

    }

    while(t2){
        int x=t2->val;

        ListNode *temp=new ListNode((x+c)%10);
        c=(x+c)/10;

        if(head==NULL)
        {
            head=temp;
            t3=head;
        }
        else{
            t3->next=temp;
            t3=t3->next;
        }

        t2=t2->next;

    }
    if(c!=0){
        ListNode *temp=new ListNode(c);
        //c=(x+c)/10;

        if(head==NULL)
        {
            head=temp;
            t3=head;
        }
        else{
            t3->next=temp;
            t3=t3->next;
        }
    }

    return head;

  }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=reverse(l1);
        ListNode* h2=reverse(l2);
        
        ListNode* head=addNum(h1,h2);
        
        return reverse(head);
    }
};
