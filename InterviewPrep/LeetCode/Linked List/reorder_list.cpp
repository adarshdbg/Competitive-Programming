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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL,*Next=head;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    void print(ListNode* h){
        if(!h){
            return ;
        }
        cout<<h->val<<" ";
        print(h->next);
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        ListNode* h=head,*ans=head;
        ListNode* a=head->next;
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        h=slow->next;
        slow->next=NULL;
        a=h;
        a=reverse(h);
        ListNode* b=head;
        while(b && a){
            ListNode* c=b->next;
            b->next=new ListNode(a->val);
            a=a->next;
            b->next->next=c;
            b=c;
        }
        head=ans;
    }
};
