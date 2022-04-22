class MyHashMap {
    int* hash;
public:
    MyHashMap() {
        hash = new int[1000006];
        for (int i = 0; i < 1000006; i++) hash[i] = -1;
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};