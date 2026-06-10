class MinStack {
public:
    vector<vector<int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        int minVal = getMin();
        if(st.size() == 0 || minVal > value){
            minVal = value;
        }
        st.push_back({value, minVal});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.size() == 0 ? -1 : st.back()[0];
    }
    
    int getMin() {
        return st.size() == 0 ? -1 : st.back()[1];
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