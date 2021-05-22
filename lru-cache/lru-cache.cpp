class LRUCache {
public:
    int cap;
    list<int> dq;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            dq.erase(cache[key].second);
            dq.push_front(key);
            cache[key] = {cache[key].first, dq.begin()};
            return cache[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            // cout<<"update "<<key<<endl;
            dq.erase(cache[key].second);
        }
        else if(dq.size()==cap){
            cache.erase(dq.back());
            // cout<<"erased "<<dq.back()<<endl;
            dq.pop_back();
        }
        // cout<<"add "<<key<<endl;
        dq.push_front(key);
        cache[key] = {value, dq.begin()};
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */