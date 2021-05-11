#define pi pair<int, int>
#define s second
#define f first
class Solution {
public:
    template<class E>
    void sortv(vector<E>& v){
        sort(v.begin(), v.end());
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        vector<int> Q = queries;
        sortv(intervals);
        sortv(queries);
        
        unordered_map<int, int> m;
        int i = 0;
        int n = intervals.size();
        for(int q:queries){
            while(i<n && intervals[i][0]<=q){
                pq.push({intervals[i][1]-intervals[i][0]+1, i});
                i++;
            }
            
            while(!pq.empty() && intervals[pq.top().s][1]<q){
                pq.pop();
            }
            
            m[q] = (!pq.empty())?pq.top().f : -1;
            
        }
        
        vector<int> ans;
        
        for(int q:Q){
            ans.push_back(m[q]);
        }
        return ans;
    }
};