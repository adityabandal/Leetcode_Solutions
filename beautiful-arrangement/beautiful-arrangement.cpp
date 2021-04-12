class Solution {
public:
    // bool vis[16];
    // int ans;
    int dp[16][100000];
    int help(int n, int curr, unsigned int vis){
        if(curr == n+1) return 1;
        if(dp[curr][vis]!=-1) return dp[curr][vis];
        else{
            int ans = 0;
            for(int i=1;i<=n;i++){
                if(!(vis>>i & 1)){
                    if(curr%i ==0 || i%curr==0){
                        vis |= 1<<i;
                        ans += help(n, curr+1, vis);
                        vis ^= 1<<i;
                    }
                }
            }
            return dp[curr][vis] = ans;
        }
    }
    int countArrangement(int n) {
        memset(dp, -1, sizeof(dp));
        unsigned int vis = 0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            vis |= 1<<i;
            // cout<<vis<<endl;
            ans += help(n, 2, vis);
            vis ^= 1<<i;
        }
        return ans;
    }
};