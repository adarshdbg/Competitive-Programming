#include <bits/stdc++.h>
using namespace std;
#define ll node

class ll{
    public:
        int val;
        ll*next;
        ll(int val){
            this->val=val;
            this->next=NULL;
        }
};


node* add(node* h,int n){
    node* t=h;
    if(!h){
        h=new node(n);
        return h;
    }
    while(t->next){
        t=t->next;
    }
    t->next=new node(n);
    return h;
}

pair<int,node*> add_one(node* head){
    if(!head){
        return make_pair(1,head);
    }
    pair<int,node*> temp=add_one(head->next);
    node* h=temp.second;
    int c=temp.first;
    int tt=head->val;
    head->val=(head->val+c)%10;
    c=(tt+c)/10;
    return make_pair(c,head);
}

void print(node* head){
    if(!head){
        return ;
    }
    cout<<head->val<<" ";
    print(head->next);
}

int main() {

    int n;
    cin>>n;
    node* head=NULL;
    while(n--){
        int x;
        cin>>x;
        head=add(head,x);
    }

    pair<int,node*> t=add_one(head);
    if(t.first==0){
        print(t.second);
    }
    else{
        node* h=new node(t.first);
        h->next=t.second;
    }
    return 0;
}
