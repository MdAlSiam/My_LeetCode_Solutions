class MyStack {
    queue<int> q;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while (!q.empty()) {
            q2.push(q.front());
            q.pop();
        }
        swap(q, q2);
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};