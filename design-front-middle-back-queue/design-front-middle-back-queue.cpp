class FrontMiddleBackQueue {
public:
    deque<int> l,r;
    FrontMiddleBackQueue() {
        
    }
    void bal(){
        if(l.size()>r.size()){
            r.push_front(l.back());
            l.pop_back();
        }
        else if(r.size()>l.size()+1){
            l.push_back(r.front());
            r.pop_front();
        }
    }
    void pushFront(int val) {
        l.push_front(val);
        bal();
    }
    
    void pushMiddle(int val) {
        l.push_back(val);
        bal();
    }
    
    void pushBack(int val) {
        r.push_back(val);
        bal();
    }
    
    int popFront() {
        if(l.size()==0&&r.size()==0) return -1;
        int ans = -1;
        if(l.size()==0){
            ans = r.front();
            r.pop_front();
        }
        else{
            ans = l.front();
            l.pop_front();
        }
        bal();
        return ans;
    }
    
    int popMiddle() {
        if(l.size()==0&&r.size()==0) return -1;
        int ans = -1;
        if(l.size()==r.size()){
            ans = l.back();
            l.pop_back();
        }
        else{
            ans = r.front();
            r.pop_front();
        }
        bal();
        return ans;
    }
    
    int popBack() {
        if(l.size()==0&&r.size()==0) return -1;
        int ans = r.back();
        r.pop_back();
        bal();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */