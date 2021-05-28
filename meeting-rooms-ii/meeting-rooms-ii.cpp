class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& in) {
        int dp[1000001];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<in.size();i++){
            dp[in[i][0]]++;
            dp[in[i][1]]--;
        }
        int ans = dp[0];
        for(int i=1;i<1000001;i++){
            dp[i]+=dp[i-1];
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};