#define ll long long
class Solution {
public:
    
    int kInversePairs(int n, int k) {
        if(k>n*(n-1)/2) return 0;
        if(n==1) return 1;
        int M = 1e9+7;
        // if(k==0)return 1;
        // int N = n*(n-1)/2;
        k++;
        ll dp[n][k];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        
        for(int i=1;i<n;i++){
            ll sum = 0;
            // dp[i][0] = 1;
            for(int j=0;j<k;j++){
                sum = sum+dp[i-1][j];
                if(j>i)
                    sum = (sum - dp[i-1][j-i-1]);
                // sum%=M;
                dp[i][j] = sum%M;
            }
            
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[n-1][k-1];
    }
};