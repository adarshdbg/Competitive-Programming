#include<bits/stdc++.h>
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> a;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> b;
        while(a.size()!=1){
            int top=a.top();
            b.push(top);
            a.pop();
        }
        int ans=a.top();
        a.pop();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> b;
        while(a.size()!=1){
            int top=a.top();
            b.push(top);
            a.pop();
        }
        int ans=a.top();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return ans;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
