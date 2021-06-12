class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& st) {
        int n = st.size();
        
        priority_queue<int> pq;
        int prev = 0, ans = 0, tank = startFuel;
        
        for(int i=0;i<n;i++){
            tank -= st[i][0]-prev;
            while(!pq.empty() && tank<0){
                tank+=pq.top();
                pq.pop();
            }
            if(tank<0) return -1;
            pq.push(st[i][1]);
            prev = st[i][0];
        }
        
        tank-=target-prev;
        while(!pq.empty() && tank<0){
            tank+=pq.top();
            pq.pop();
        }
        if(tank<0) return -1;
        return n-pq.size();
    }
};