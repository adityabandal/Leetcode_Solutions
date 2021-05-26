class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> r;
    priority_queue<int> l;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.size() == 0){
            l.push(num);
        }
        else if(l.size() > r.size()){
            if(num <= l.top()){
                l.push(num);
                r.push(l.top());
                l.pop();
            }
            else{
                r.push(num);
            }
        }
        else{
            if(num <= l.top()){
                l.push(num);
            }
            else{
                r.push(num);
                l.push(r.top());
                r.pop();
            }
        }
    }
    
    double findMedian() {
        if(l.size()==r.size() && l.size()>0){
            return (((double)l.top()+(double)r.top())/2);
        }
        else{
            return l.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */