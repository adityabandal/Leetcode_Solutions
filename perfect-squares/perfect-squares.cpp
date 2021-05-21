class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        // memset(dp, 10000, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = INT_MAX;
            // cout<<dp[i]<<endl;
            
            for(int j=1;j*j<=i;j++){
                // cout<<"->"<<i-j*j<<" "<<dp[i-j*j]<<" "<<1+dp[i-j*j]<<endl;
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
            // cout<<dp[i]<<endl;
        }
        
        return dp[n];
    }
};