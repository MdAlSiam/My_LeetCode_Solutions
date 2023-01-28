class SummaryRanges {
    set<int> nums;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;

        int start = -1;
        int end = -1;

        for (int num : nums) {
            if (start == -1) {
                start = num;
                end = num;
            }
            else if (end+1 == num) {
                end = num;
            }
            else {
                ret.push_back({start, end});
                start = num;
                end = num;
            }
        }
        if (start != -1) {
            ret.push_back({start, end});
        }

        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */