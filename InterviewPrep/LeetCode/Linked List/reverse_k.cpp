/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define ll long long
class Solution {
public:
    
    ll len(ListNode* head){
        ll cnt=0;
        ListNode*ans=head;
        while(ans){
            cnt++;
            ans=ans->next;
        }
        return cnt;
    }
    
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
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ll cnt=0;
        if(len(head)<k){
            return head;
        }
        ListNode* t=head;
        while(cnt<k-1){
            t=t->next;
            cnt++;
        }
        ListNode* head2=t->next;
        t->next=NULL;
        ListNode* HEAD=reverse(head);
        ListNode* temp=head;
        ListNode* h=reverseKGroup(head2,k);
        t=HEAD;
        while(t->next){
            t=t->next;
        }
        t->next=h;
        return HEAD;
    }
};
