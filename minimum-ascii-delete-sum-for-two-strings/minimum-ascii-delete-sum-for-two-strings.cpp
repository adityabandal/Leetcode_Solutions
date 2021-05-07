class Solution {
public:
    int minimumDeleteSum(string w1, string w2) {
        int l1 = w1.size();
        int l2 = w2.size();
        
        int dp[l1+1][l2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                if(w1[i]==w2[j]){
                    dp[i+1][j+1] = (int)w1[i]+dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        int sum = 0;
        for(char c:w1) sum+=(int)c;
        for(char c:w2) sum+=(int)c;
        return sum-2*dp[l1][l2];
    }
};