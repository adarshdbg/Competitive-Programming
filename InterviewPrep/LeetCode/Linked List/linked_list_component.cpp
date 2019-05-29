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
    int numComponents(ListNode* head, vector<int>& G) {
        int ans=0;
        map<int,int> m;
        for(int i:G)m[i]++;
        while(head){
            ListNode* t=head;
            while(t&&m[t->val]){
                t=t->next;
            }
            if(t==head){
                head=head->next;
            }
            else{
                head=t;
                ans++;
            }
        }
        return ans;
    }
};
