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
    int len(ListNode* head){
        map<ListNode*,int> m;
        int ans=0;
        while(head){
            if(m.count(head)){
                return ans;
            }
            m[head]++;
            ans++;
            head=head->next;
        }
    }
    #define null NULL
    ListNode *detectCycle(ListNode *head) {
        if (head == null) return null;
         
        ListNode* slow = head;
        ListNode* fast = head;
         
        while (fast != null && fast->next != null) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
         
        // check if the list has no cycle
        if (fast == null || fast->next == null) 
            return null;
         
        // find the entrance of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
