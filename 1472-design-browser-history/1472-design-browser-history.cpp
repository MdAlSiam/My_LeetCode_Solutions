class BrowserHistory {
    vector<string> pages;
    int pointer = -1;
public:
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        pointer++;
    }
    
    void visit(string url) {
        while (pages.size()-1 != pointer) {
            pages.pop_back();
        }

        pages.push_back(url);
        pointer++;
    }
    
    string back(int steps) {
        pointer -= steps;
        if (pointer < 0) pointer = 0;
        return pages[pointer];
    }
    
    string forward(int steps) {
        pointer += steps;
        if (pointer >= pages.size()) pointer = pages.size()-1;
        return pages[pointer];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */