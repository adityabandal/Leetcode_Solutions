class Solution {
public:
    vector<int> disc, low, parent;
    vector<vector<int>> ans;
    void dfs(int n, vector<int> adj[], int curr, int prev, int time){
        // if(parent[curr]!=INT_MIN) return;
        
        parent[curr] = prev;
        low[curr] = disc[curr] = time;
        for(int v:adj[curr]){
            if(parent[v]==INT_MIN){
                dfs(n, adj, v, curr, time+1);
                if(low[v]>time) ans.push_back({curr, v});
                low[curr] = min(low[v], low[curr]);
            }
            else if(v!=prev){
                low[curr] = min(low[curr], low[v]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        disc = vector<int>(n, -1);
        low = vector<int>(n, INT_MAX);
        parent = vector<int>(n, INT_MIN);
        for(auto e:connections){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        dfs(n, adj, 0, -1, 0);
        return ans;
    }
};