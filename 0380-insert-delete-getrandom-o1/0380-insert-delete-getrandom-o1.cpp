class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }

    bool search(int val){
        if(find(v.begin(), v.end(), val) != v.end())
            return true;

        return false;
    }
    
    bool insert(int val) {
        if(search(val)) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)) return false;
        int index = mp[val];
        int last = v.back();
        v[index] = last;
        mp[last] = index;
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[random()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */