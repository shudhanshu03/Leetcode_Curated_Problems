class RandomizedSet {
    unordered_map<int,int> st;
    vector<int> track;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
          if (st.find(val) != st.end()) return false;
        track.emplace_back(val);
        st[val] = track.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (st.find(val) == st.end()) return false;
        int last = track.back();
        st[last] = st[val];
        track[st[val]] = last;
        track.pop_back();
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        return track[rand() % track.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */