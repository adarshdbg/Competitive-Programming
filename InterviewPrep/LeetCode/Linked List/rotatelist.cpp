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
    
    int len(ListNode* head){
        int ans=0;
        while(head){
            ans++;
            head=head->next;
        }
        return ans;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        int l=len(head);
        if(k==l){
            return head;
        }
        if(k>l){
            k%=l;
        }
        if(k==0){
            return head;
        }
        int k1=l-k;
        int cnt=0;
        ListNode* t=head;
        while(cnt<k1-1){
            cnt++;
            t=t->next;
        }
        ListNode* h=t->next;
        t->next=NULL;
        t=h;
        while(t->next){
            t=t->next;
        }
        t->next=head;
        return h;
    }
};
