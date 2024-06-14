class MinStack {
private:
    vector<int> v;
    int min = INT_MAX;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        this->v.push_back(val);
        if (this->min > val) {
            this->min = val;
        }
    }
    
    void pop() {
        this->v.pop_back();
        this->min = INT_MAX;
        for (auto x : v) {
            if (this->min > x) {
                this->min = x;
            }
        }
    }
    
    int top() {
        return this->v.back();
    }
    
    int getMin() {
        return this->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */