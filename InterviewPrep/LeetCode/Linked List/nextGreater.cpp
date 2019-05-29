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
    
    vector<int> nextgreater(vector<int> a){
        vector<int> ans(a.size(),-1);
        stack<int> s;
        s.push(0);
        for(int i=1;i<a.size();i++){
            if(a[i]<a[s.top()]){
                s.push(i);
            }
            else{
                while(!s.empty() && a[s.top()]<a[i]){
                    ans[s.top()]=a[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            ans[s.top()]=0;
            s.pop();
        }
        return ans;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* h=head;
        vector<int> a;
        stack<int> s;
        while(h){
            a.push_back(h->val);
            h=h->next;
        }
        vector<int> ans=nextgreater(a);
        return ans;
    }
};
