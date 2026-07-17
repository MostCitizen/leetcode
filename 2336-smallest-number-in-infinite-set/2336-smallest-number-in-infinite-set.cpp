class SmallestInfiniteSet {
public:
    set<int> s;
    int index;
    SmallestInfiniteSet() {
        index = 1;
    }
    
    int popSmallest() {
        if(!s.empty()){
            int val = *s.begin();
            s.erase(s.begin());
            return val;
        }
        return index++;
    }
    
    void addBack(int num) {
        if(index > num && s.count(num) == 0){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */