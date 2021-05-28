#define pi pair<int, int>
class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        priority_queue<pi> pq;
        
        for(int i=0;i<bt.size();i++){
            pq.push({bt[i][1], bt[i][0]});
        }
        int ans = 0;
        while(ts>0 && !pq.empty()){
            pi tmp = pq.top();
            pq.pop();
            int num = tmp.second;
            int units = tmp.first;
            
            ans += min(ts, num)*units; 
            ts -= min(ts, num);
        }
        
        return ans;
    }
};