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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL,*Next=head;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    bool issame(ListNode* a,ListNode* b){
        while(a && b){
            if(a->val!=b->val){
                return false;
            }
            a=a->next;
            b=b->next;
        }
        if(!a && !b){
            return true;
        }
        if(!a || !b){
            return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        int i=0,j=a.size()-1;
        bool flag=true;
        while(i<=j){
            if(a[i]!=a[j]){
                flag=false;
                break;
            }
            i++;
            j--;
        }
        return flag;
    }
};
