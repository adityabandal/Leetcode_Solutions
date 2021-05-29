class Solution {
public:
    int dp[5001] = {};
    int change(int amount, vector<int>& coins) {
        dp[0] = 1;
        
        for(int j=0;j<coins.size();j++){
            for(int i=coins[j];i<=amount;i++){
                dp[i]+=dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};