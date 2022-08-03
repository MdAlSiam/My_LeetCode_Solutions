class MyCalendar {
    vector<pair<int, int>> v;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        end--;
        for (int i = 0; i < v.size(); i++) {
            if (start >= v[i].first and start <= v[i].second) return false;
            if (end >= v[i].first and end <= v[i].second) return false;
            if (v[i].first >= start and v[i].first <= end) return false;
            if (v[i].second >= start and v[i].second <= end) return false;
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */