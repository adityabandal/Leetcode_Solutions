class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0][1]=0;
        dp[0][0] = dp[0][2] = 1;
        for(int i=1;i<n;i++){
            int mn = INT_MAX;
            for(int j=0;j<3;j++){
                if(obstacles[i]-1==j) continue;
                else dp[i][j] = dp[i-1][j];
                mn = min(dp[i][j], mn);
            }
            for(int j=0;j<3;j++){
                if(obstacles[i]-1==j) continue;
                dp[i][j] = min(dp[i][j], mn+1);
            }
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};