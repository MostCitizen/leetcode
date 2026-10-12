class MinStack {
public:
    deque<pair<int, int>> q;
    int m = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        m = min(value, m);
        q.push_back({value, m});
    }
    
    void pop() {
        q.pop_back();
        m = !q.empty() ? q.back().second : INT_MAX;
    }
    
    int top() {
        return q.back().first;
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */