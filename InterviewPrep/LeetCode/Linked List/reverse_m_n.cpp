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
        ListNode* curr=head;//1
        ListNode* prev=NULL,*Next=head;
        while(curr){
            Next=curr->next;//null
            curr->next=prev;
            prev=curr;//1
            curr=Next;//2
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n){
            return head;
        }
        if(m==1){
            ListNode* h=head;
            int cnt=0;
            while(cnt<n-1){
                cnt++;
                h=h->next;
            }
            ListNode* t=h->next;
            h->next=NULL;
            head=reverse(head);
            h=head;
            while(h->next){
                h=h->next;
            }
            h->next=t;
            return head;
        }
        ListNode* a=head;
        int cnt=0;
        while(cnt<m-2){
            cnt++;
            a=a->next;
        }
        ListNode* head1=a->next;
        ListNode* b=head;
        cnt=0;
        while(cnt<n-1){
            cnt++;
            b=b->next;
        }
        ListNode* head2=b->next;
        a->next=NULL;
        b->next=NULL;
        ListNode* ap=reverse(head1);
        a=head;
        while(a->next){
            a=a->next;
        }
        a->next=ap;
        a=ap;
        while(a->next){
            a=a->next;
        }
        a->next=head2;
        return head;
    }
};
