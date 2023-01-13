class MedianFinder {
private:
    priority_queue<double> left;
    priority_queue <double, vector<double>, greater<double>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() && right.empty()) {
           left.push(num); 
        } else if (!left.empty() && right.empty()) {
            if (left.top() > num) {
                left.push(num);
                right.push(left.top());
                left.pop();
            } else {
                right.push(num);
            }
        } else if (left.empty() && !right.empty()) {
            if (right.top() < num) {
                right.push(num);
                left.push(right.top());
                right.pop();
            } else {
                left.push(num);
            }
        } else {
            if (left.top() > num) {
                if (left.size() > right.size()) {
                    left.push(num);
                    right.push(left.top());
                    left.pop();
                } else {
                    left.push(num);
                }
            } else if (right.top() < num) {
                if (right.size() > left.size()) {
                    right.push(num);
                    left.push(right.top());
                    right.pop();
                } else {
                    right.push(num);
                }
            } else {
                if (right.size() > left.size()) {
                    left.push(num);
                } else {
                    right.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if (right.empty() && left.empty()) {
            return NULL;
        } else if (!right.empty() && left.empty()) {
            return right.top();
        } else if (right.empty() && !left.empty()) {
            return left.top();
        } else {
            if (right.size() > left.size()) {
                return right.top();
            } else if (right.size() < left.size()) {
                return left.top();
            }else {
                return (left.top() + right.top())/2.0;
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */