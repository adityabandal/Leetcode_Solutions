class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int help(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(matrix[i][j] == -1 || matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else{
            int dx[] = {1,0,-1,0,1};
            int ans = 0;
            int curr = matrix[i][j];
            matrix[i][j] = -1;
            for(int t=0;t<4;t++){
                ans = max(ans, help(matrix, i+dx[t], j+dx[t+1], curr)+1);
            }
            matrix[i][j] = curr;
            return dp[i][j] = ans;
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)
                ans = max(ans, help(matrix, i, j, -1));
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";        
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return ans;
    }
};