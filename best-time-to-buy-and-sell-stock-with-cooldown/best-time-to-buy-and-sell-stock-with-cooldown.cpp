class Solution {
public:
    int findMaxProfit(vector<int>&prices,bool f,int day,vector<vector<int>>&dp){
        if(day>=prices.size())return 0;
        if(dp[f][day]!=-1)return dp[f][day];
        if(!f){
            int x = findMaxProfit(prices,!f,day+1,dp) - prices[day];
            int y = findMaxProfit(prices,f,day+1,dp);
            return dp[f][day] = max(x,y);
        }
			int x  = prices[day] + findMaxProfit(prices,!f,day+2,dp);
			int y  = findMaxProfit(prices,f,day+1,dp);
        return dp[f][day] = max(x,y); 
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(2,vector<int>(prices.size(),-1));
        return findMaxProfit(prices,false,0,dp);
    }
};