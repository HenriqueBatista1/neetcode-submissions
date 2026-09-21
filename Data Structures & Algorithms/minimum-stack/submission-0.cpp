class MinStack {
private:
    stack<int> s;
    stack<int> minimum;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minimum.empty()) minimum.push(val);
        else minimum.push(min(val, minimum.top()));
    }
    
    void pop() {
        s.pop();
        minimum.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};
