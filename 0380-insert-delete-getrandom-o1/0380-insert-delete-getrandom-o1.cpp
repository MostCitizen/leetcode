class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> map;
    int index = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.contains(val) && map[val] != -1) return false;
        map[val] = index++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!map.contains(val) || map[val] == -1) return false;
        int idx = map[val];
        v[idx] = v[index-1];
        v.pop_back();
        map[val] = -1;
        if(v[idx] != val)
            map[v[idx]] = idx;
        index--;
        return true;
    }
    
    int getRandom() {
        return v[rand() % index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */