class MyCalendar {
public:
    set<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = events.lower_bound({start, end});
        
        if(it!=events.end()){
            if(it->first < end) return false;
        }
        if(it!=events.begin()){
            if((--it)->second > start) return false;
        }
        events.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */