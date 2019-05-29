/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define ll long long 
class cmp{
  public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        vector<ListNode*> a;
        for(ll i=0;i<lists.size();i++){
            if(lists[i]==NULL){
                continue;
            }
            else{
                a.push_back(lists[i]);
            }
        }
        if(a.size()==0){
            return NULL;
        }
        ListNode* h=new ListNode(1);
        ListNode* H=h;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(ll i=0;i<a.size();i++){
            pq.push(a[i]);
        }
        while(pq.top() && pq.top()->val!=INT_MAX){
            ListNode*t=pq.top();
            h->next=new ListNode(t->val);
            h=h->next;
            ListNode* tt=new ListNode(INT_MAX);
            pq.pop();
            if(t->next)
                pq.push(t->next);
            else
                pq.push(tt);
        }
              return H->next;
    }
};
