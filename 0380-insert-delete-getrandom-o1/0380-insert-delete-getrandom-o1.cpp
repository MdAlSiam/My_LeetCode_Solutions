class RandomizedSet {
    map<int, int> numMap; // value -> index
    vector<int> numList;
public:
    RandomizedSet() {
        numMap.clear();
        numList.clear();
    }
    
    bool insert(int val) {
        bool ret = !numMap.count(val);

        if (ret) {
            numMap[val] = numList.size();
            numList.push_back(val);
        }

        return ret;
    }
    
    bool remove(int val) {
        bool ret = numMap.count(val);

        if (ret) {
            int idx = numMap[val];
            int lastVal = numList[numList.size()-1];
            numList[idx] = lastVal;
            numList.pop_back();
            numMap[lastVal] = idx;
            numMap.erase(val);
        }

        return ret;
    }
    
    int getRandom() {
        int rand_idx = rand() % numList.size();
        return numList[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */