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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode* h=new ListNode(1);
        ListNode* H=h,*head2=head;
        while(head2){
            if(m[head2->val]==0){
                h->next=new ListNode(head2->val);
                h=h->next;
                m[head2->val]++;
            }
            head2=head2->next;
        }
        return H->next;
    }
};
