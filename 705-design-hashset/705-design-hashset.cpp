class MyHashSet {
    bool* ara;
public:
    MyHashSet() {
        ara = new bool[1000006];
        for (int i = 0; i < 1000006; i++) {
            ara[i] = false;
        }
    }
    
    void add(int key) {
        ara[key] = true;
    }
    
    void remove(int key) {
        ara[key] = false;
    }
    
    bool contains(int key) {
        return ara[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */