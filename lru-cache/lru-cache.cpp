class LRUCache {
public:
    list<int> lst;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        
        lst.erase(cache[key].second);
        lst.push_front(key);
        cache[key] = {cache[key].first, lst.begin()};
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            lst.erase(cache[key].second);
        }
        else if(lst.size() == sz){
            cache.erase(lst.back());
            lst.pop_back();
        }
        lst.push_front(key);
        cache[key] = {value, lst.begin()};
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */