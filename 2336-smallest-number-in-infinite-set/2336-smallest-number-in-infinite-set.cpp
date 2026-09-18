class SmallestInfiniteSet {
public:
    int count = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(pq.empty()) return count++;
        int val = pq.top();
        pq.pop();
        s.erase(val);
        return val;
    }
    
    void addBack(int num) {
        if(count <= num || s.contains(num)) return;
        pq.push(num);
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */