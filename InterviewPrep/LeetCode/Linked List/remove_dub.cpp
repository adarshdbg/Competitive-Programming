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
    void print(ListNode* h){
        if(!h){
            return ;
        }
        cout<<h->val<<" ";
        print(h->next);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head2=head;
        ListNode* h=new ListNode(1);
        ListNode* H=h;
        map<int,int> m;
        while(head2){
            m[head2->val]++;
            head2=head2->next;
        }
        head2=head;
        while(head2){
            if(m[head2->val]==1){
                h->next=new ListNode(head2->val);
                h=h->next;
            }
            head2=head2->next;
        }
        return H->next;
    }
};
