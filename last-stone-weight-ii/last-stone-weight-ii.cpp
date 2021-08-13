class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum =  0;
        vector<bool> dp(1501,false); //size = (max len) * (mx wt)/2
        dp[0]=true;
        for(int s:stones){ // for each stone
            sum += s; // maintain sum of stones 0..current index
            for(int i=min(1500,sum);i>=s;i--){ //from sum to s
                dp[i] = dp[i] | dp[i-s]; // if i-s is possible 
            }
        }
        for(int i=sum/2;i>=0;i--){
            if(dp[i]){
                return sum-i-i;
            }
        }
        return 0;
    }
};