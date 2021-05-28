class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int s:sticks) pq.push(s);
        int ans=0;
        while(pq.size()>1){
            int p = pq.top();
            pq.pop();
            p+=pq.top();
            pq.pop();
            ans+=p;
            pq.push(p);
        }
        return ans;
    }
};