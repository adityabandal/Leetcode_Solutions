class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char, int> m;
        m['a'] = 0;
        m['e'] = 1;
        m['i'] = 2;
        m['o'] = 3;
        m['u'] = 4;
        long long int dp[n][5];
        int M = 1e9+7;
        memset(dp, 0, sizeof(dp));
        for(int j=0;j<5;j++) dp[n-1][j] = 1;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<5;j++){
                if(j==m['a']){
                    dp[i][j] = dp[i+1][m['e']];
                }
                else if(j==m['e']){
                    dp[i][j] = (dp[i+1][m['a']]+dp[i+1][m['i']])%M;
                }
                else if(j==m['i']){
                    dp[i][j] = (((dp[i+1][m['a']]+dp[i+1][m['e']])%M+dp[i+1][m['o']])%M+dp[i+1][m['u']])%M;
                }
                else if(j==m['o']){
                    dp[i][j] = (dp[i+1][m['i']]+dp[i+1][m['u']])%M;
                }
                else if(j==m['u']){
                    dp[i][j] = dp[i+1][m['a']];
                }
                
                dp[i][j] %= M;
            }
        }
        int ans = 0;
        for(int j=0;j<5;j++){
            ans = (ans+dp[0][j])%M;
        }
        return ans;
        
    }
};