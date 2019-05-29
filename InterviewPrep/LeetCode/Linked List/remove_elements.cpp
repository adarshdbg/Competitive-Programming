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
    ListNode* removeElements(ListNode* head, int val) {
        vector<int> a;
        ListNode* h=head;
        while(h){
            if(h->val!=val){
                a.push_back(h->val);
            }
            h=h->next;
        }
        ListNode* ans=new ListNode(1);
        ListNode* r=ans;
        for(int i:a){
            ans->next=new ListNode(i);
            ans=ans->next;
        }
        return r->next;
    }
};
