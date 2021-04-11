class KthLargest {
public:
    priority_queue<int> r;
    priority_queue<int, vector<int>, greater<int>> l;
    // int l,r;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // l=0;
        // r=0;
        this->k = k;
        for(int n:nums){
            add(n,1);
        }
    }
    
    void add(int val, int x){
        if(l.size()<k){
            l.push(val);
        }
        else{
            if(l.top() > val){
                r.push(val);
            }
            else{
                int tmp = l.top();
                l.pop();
                r.push(tmp);
                l.push(val);
            }
        }
    }
    int add(int val) {
        if(l.size()<k){
            l.push(val);
        }
        else{
            if(l.top() > val){
                r.push(val);
            }
            else{
                int tmp = l.top();
                l.pop();
                r.push(tmp);
                l.push(val);
            }
        }
        return l.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */