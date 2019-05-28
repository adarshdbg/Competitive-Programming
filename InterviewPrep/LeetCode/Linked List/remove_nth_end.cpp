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
    int length(ListNode* head){
        ListNode* t=head;
        int ans=0;
        while(t){
            ans++;
            t=t->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(length(head)<n){
            n=(length(head))%n+1;   
        }
        if(n==length(head)){
            if(head==NULL) return head;
            return head->next;
        }
        ll cnt=0;
        ListNode* t=head;
        ll l=length(head);
        while(cnt<l-n-1){
            cnt++;
            t=t->next;
        }
        if(t->next==NULL){
            t->next=NULL;
        }
        else{
            t->next=t->next->next;
        }
        return head;
    }
};
