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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=NULL,*even=NULL;
        odd=new ListNode(1);
        even=new ListNode(2);
        ListNode* a=odd,*b=even;
        int i=0;
        while(head){
            if(i%2==0){
                odd->next=new ListNode(head->val);
                odd=odd->next;
            }
            else{
                even->next=new ListNode(head->val);
                even=even->next;
            }
            head=head->next;
            i++;
        }
        odd->next=b->next;
        return a->next;
    }
};
