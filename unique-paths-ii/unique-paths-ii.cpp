class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        if(og[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(og[i][0]!=1){
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int j=1;j<n;j++){
            if(og[0][j]!=1){
                dp[0][j]=dp[0][j-1];
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(og[i][j]!=1){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};