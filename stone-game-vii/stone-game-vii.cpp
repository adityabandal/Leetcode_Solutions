class Solution {
public:
    int dp[1001][1001][2];
    int help(vector<int>& stones, int lo, int hi, int isAlice, int sum){
        if(lo>hi){
            return 0;
        }
        if(dp[lo][hi][isAlice]!=-1) return dp[lo][hi][isAlice];
        else{
            if(isAlice){
                return dp[lo][hi][1] =   max( sum-stones[lo] + help(stones, lo+1, hi, 1-isAlice, sum-stones[lo]),
                            sum-stones[hi] + help(stones, lo, hi-1, 1-isAlice, sum-stones[hi])
                            );
            }
            else{
                return dp[lo][hi][0] = min( - (sum-stones[lo]) + help(stones, lo+1, hi, 1-isAlice, sum-stones[lo]),
                            - (sum-stones[hi]) + help(stones, lo, hi-1, 1-isAlice, sum-stones[hi])
                            );
            }
        }
        
    }
    int stoneGameVII(vector<int>& stones) {
        
        memset(dp, -1, sizeof(dp));
        
        int sum = 0;
        for(int s:stones) sum+=s;
        
        return help(stones, 0, stones.size()-1, 1, sum);
    }
};