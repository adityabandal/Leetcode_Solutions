#define pi pair<int, int>
#define s second
#define f first
#define ull unsigned long long int
class Solution {
public:
    void print2d(const vector<vector<int>>& dp){
        int n = dp.size();
        int m = dp[0].size();
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<dp[i][j]<<" ";      
                }
                cout<<endl;
            }
            cout<<endl;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        // vector<vector<int>> a;
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        // print2d(tasks);
        priority_queue<pair<pi, int>, vector<pair<pi, int>>, greater<pair<pi, int>>> pq;
        ull t = tasks[0][0];
        int i = 0;
        while(i<n && tasks[i][0]==t){
            pq.push({{tasks[i][1], tasks[i][2]}, tasks[i][0]});
            i++;
        }
        // while(!pq.empty()){
        //     cout<<pq.top().s<<endl;
        //     pq.pop();
        // }
        vector<int> ans;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                t = tasks[i][0];
                while(i<n && tasks[i][0]==t){
                    pq.push({{tasks[i][1], tasks[i][2]}, tasks[i][0]});
                    i++;
                }
                continue;
            }
            int pid = pq.top().f.s;
            int time = pq.top().f.f;
            ans.push_back(pid);
            t += time;
            pq.pop();
            while(i<n && tasks[i][0]<=t){
                pq.push({{tasks[i][1], tasks[i][2]}, tasks[i][0]});
                i++;
            }
        }
        return ans;
    }
};