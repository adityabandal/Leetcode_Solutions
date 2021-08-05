class Solution {
public:
    int dp[501][501];
    // int help(vector<int>& piles, int lo, int hi){
    //     if(lo>hi) return 0;
    //     if(dp[lo][hi]!=-1) return dp[lo][hi];
    //     bool alex = (piles.size()-(hi-lo+1))%2==0;
    //     if(alex){
    //         return dp[lo][hi] = max(help(piles,lo+1,hi)+piles[lo], help(piles, lo, hi-1)+piles[hi]);
    //     }
    //     else{
    //         return dp[lo][hi] = min(help(piles,lo+1,hi)-piles[lo], help(piles, lo, hi-1)-piles[hi]);
    //     }
    // }
    bool stoneGame(vector<int>& piles) {
        memset(dp, 0, sizeof(dp));
        int n = piles.size();
        for(int i=0;i<n;i++){
            dp[i][i] = piles[i];
            if((n-1)%2==1){
                dp[i][i]*=-1;
            }
        }
        
        for(int j=1;j<n;j++){
            for(int i=0;i+j<n;i++){
                int start = i;
                int end = i+j;
                
                bool alex = (n-j-1)%2==0;
                if(alex){
                    dp[start][end] = max(piles[start]+dp[start+1][end], piles[end]+dp[start][end-1]);
                }
                else{
                    dp[start][end] = min(-piles[start]+dp[start+1][end], -piles[end]+dp[start][end-1]);
                }
            }
        }
        return dp[0][n-1]>0;
        // return help(piles, 0, piles.size()-1)>0;
    }
};