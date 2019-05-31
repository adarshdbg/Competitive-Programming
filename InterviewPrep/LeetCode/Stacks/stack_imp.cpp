
#include<bits/stdc++.h>
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> a;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> b;
        while(a.size()!=1){
            int top=a.front();
            a.pop();
            b.push(top);
        }
        int ans=a.front();
        a=b;
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> b;
        while(a.size()!=1){
            int top=a.front();
            a.pop();
            b.push(top);
        }
        int ans=a.front();
        a=b;
        a.push(ans);
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(a.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
