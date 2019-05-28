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
    ListNode* swapPairs(ListNode* head) {
        ListNode* t=head;
        while(t){
            if(t->next){
                swap(t->val,t->next->val);
                t=t->next->next;
            }
            else{
                t=t->next;
            }
        }
        return head;
    }
};
