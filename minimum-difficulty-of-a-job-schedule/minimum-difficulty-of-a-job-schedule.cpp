class Solution {
public:
    int dp[11][300];
    int help(vector<int>& jd, int d, int last){
        if(d>last+1) return -1;
        if(last == -1 && d == 0) return 0;
        if(last == -1 || d == 0) return -1;
        if(dp[d][last] != -1) return dp[d][last];
        
        int mx = 0, ans = INT_MAX;
        
        for(int i=last;i>=d-1;i--){
            mx = max(mx, jd[i]);
            int nxt = help(jd, d-1, i-1);
            if(nxt!=-1){
                ans = min(ans, nxt+mx);
            }
        }
        
        return dp[d][last] = ans;
        
    }
    int minDifficulty(vector<int>& jd, int d) {
        if(d>jd.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return help(jd, d, jd.size()-1);
    }
};