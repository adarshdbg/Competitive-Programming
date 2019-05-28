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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,ll c=0) {
        if(!l1 && !l2){
            ListNode* ans=NULL;
            while(c){
                if(!ans)
                    ans=new ListNode(c%10);
                else{
                    ans->next=new ListNode(c%10);
                    ans=ans->next;
                }
                c/=10;
            }
            return ans;
        }
        if(!l1){
            if(c==0)
                return l2;
            ListNode* y=l2;
            while(y){
                ll x=(y->val+c);
                y->val=(y->val+c)%10;
                c=x/10;
                if(y->next==NULL){
                    while(c){
                        y->next=new ListNode(c%10);
                        y=y->next;
                        c/=10;
                    }
                }
                y=y->next;
            }
            return l2;
        }
        if(!l2){
            if(c==0){
                return l1;
            }
            ListNode*y=l1;
            while(y){
                ll x=(y->val+c);
                y->val=(y->val+c)%10;
                c=x/10;
                if(y->next==NULL){
                    while(c){
                        y->next=new ListNode(c%10);
                        y=y->next;
                        c/=10;
                    }
                }
                y=y->next;
            }
            return l1;
        }
        ll x=(l1->val+l2->val+c);
        ListNode* ans=new ListNode((l1->val+l2->val+c)%10);
        ans->next=addTwoNumbers(l1->next,l2->next,x/10);
        return ans;
    }
};
