class Solution {
public:
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int ans = 0;
        vector<int> adj[n];
        vector<int> in(n, 0);
        for(auto e:edges){
            in[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        
        int dp[n][26];
        memset(dp, 0, sizeof(dp));
       int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            dp[curr][colors[curr]-'a']++;
            ans = max(ans, dp[curr][colors[curr]-'a']);
            // cout<<curr<<"->";
            for(int v:adj[curr]){
                for(int j=0;j<26;j++){
                    dp[v][j] = max(dp[v][j], dp[curr][j]);
                }
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<26;j++){
        //         cout<<dp[i][j]<<" ";
        //     } 
        //     cout<<endl;
        // }
        // cout<<endl;
        
        if(cnt!=colors.size()) return -1;
        return ans;
    }
};