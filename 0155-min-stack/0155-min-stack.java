class MinStack {
    List<List<Integer>> list = new ArrayList<>();

    public MinStack() {
        
    }
    
    public void push(int value) {
        int minVal = getMin();
        if(list.isEmpty() || minVal > value){
            minVal = value;
        }
        list.add(new ArrayList<>(List.of(value, minVal)));
    }
    
    public void pop() {
        if(list.size() == 0) return;
        list.remove(list.size()-1);
    }
    
    public int top() {
        return list.size() > 0 ? list.get(list.size()-1).get(0) : -1;
    }
    
    public int getMin() {
        return list.size() > 0 ? list.get(list.size()-1).get(1) : -1;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */