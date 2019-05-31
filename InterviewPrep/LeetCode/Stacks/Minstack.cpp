class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> a,M;
    MinStack() {
        a.clear();
        M.clear();
    }
    
    void push(int x) {
        a.push_back(x);
        if(M.size()==0){
            M.push_back(x);
        }
        else{
            M.push_back(min(x,M[M.size()-1]));
        }
    }
    
    void pop() {
        a.erase(a.begin()+a.size()-1);
        M.erase(M.begin()+M.size()-1);
    }
    
    int top() {
        return a[a.size()-1];
    }
    
    int getMin() {
        return M[a.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
