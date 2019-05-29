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
    int len(ListNode* h){
        int ans=0;
        while(h){
            ans++;
            h=h->next;
        }
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=len(headA);
        int b=len(headB);
        if(a>b){
            swap(a,b);
            swap(headA,headB);
        }
        /// Now , a is lesser than b.
        int c=b-a;
        int cnt=0;
        ListNode* h=headB;
        
        while(headB && cnt<=c-1){
            cnt++;
            headB=headB->next;
        }
        if(headB){
            cout<<headB->val;
        }
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        if(headA && headB){
            return headA;
        }
        return NULL;
    }
};
