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
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        
        dp[0][colors[0]-1] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                if(dp[i-1][j]!=INT_MAX){
                    dp[i][j] = 1+dp[i-1][j];
                }
            }
            dp[i][colors[i]-1] = 0;
        }
        dp[n-1][colors[n-1]-1] = 0;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<3;j++){
                if(dp[i+1][j]!=INT_MAX){
                    dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
                }
            }
            // dp[i][colors[i]-1] = 0;
        }
        // print2d(dp);
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++){
            int idx = queries[i][0];
            int c = queries[i][1]-1;
            ans.push_back(dp[idx][c]==INT_MAX?-1:dp[idx][c]);
        }
        return ans;
    }
};