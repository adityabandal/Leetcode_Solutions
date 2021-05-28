class Solution {
public:
    // int dp[11][300];
//     int help(vector<int>& jd, int d, int last){
//         if(d>last+1) return -1;
//         if(last == -1 && d == 0) return 0;
//         if(last == -1 || d == 0) return -1;
//         if(dp[d][last] != -1) return dp[d][last];
        
//         int mx = 0, ans = INT_MAX;
        
//         for(int i=last;i>=d-1;i--){
//             mx = max(mx, jd[i]);
//             int nxt = help(jd, d-1, i-1);
//             if(nxt!=-1){
//                 ans = min(ans, nxt+mx);
//             }
//         }
        
//         return dp[d][last] = ans;
        
//     }
    int minDifficulty(vector<int>& jd, int d) {
        if(d>jd.size()) return -1;
        
        int n = jd.size();
        
        int dp[n+1][d+1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = jd[0];
        for(int i=2;i<=n;i++){
            dp[i][1] = max(dp[i-1][1], jd[i-1]);
        }
        for(int j=2;j<=d;j++){
            for(int i=j;i<=n;i++){
                // cout<<i<<" "<<j<<"-> ";
                dp[i][j] = INT_MAX;
                int mx = INT_MIN;
                for(int k=i;k>=j;k--){
                    // cout<<k<<" ";
                    mx = max(mx, jd[k-1]);
                    dp[i][j] = min(dp[i][j], mx+dp[k-1][j-1]);
                }
                // cout<<endl;
            }
        }
        // cout<<endl;
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=d;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        return dp[n][d];
    }
};