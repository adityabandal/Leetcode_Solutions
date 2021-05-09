class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<long> pq;
        long sum  = 0;
        for(long t:target){
            sum += t;
            pq.push(t);
        }
        
        while(pq.top()>1){
            long high = pq.top();
            pq.pop();
            sum -= high;
            if(sum==1) return true;
            if(sum==0 || high%sum==0 || sum>high) return false;
            
            high%=sum;
            sum+=high;
            pq.push(high);
        }
        
        return true;
    }
};