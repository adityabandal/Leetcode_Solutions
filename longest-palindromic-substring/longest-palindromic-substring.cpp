class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        string ans = "";
        
        for(int i=0;i<n;i++){
            int lo = i;
            int hi = i;
            
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                if(hi-lo+1>ans.size()){
                    ans = s.substr(lo, hi-lo+1);
                }
                lo--;
                hi++;
            }
            
            lo = i;
            hi = i+1;
            
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                if(hi-lo+1>ans.size()){
                    ans = s.substr(lo, hi-lo+1);
                }
                lo--;
                hi++;
            }
        }
        
//         for(int i=0;i<n-1;i++){
//             int lo = i;
//             int hi = i+1;
            
//             while(lo>=0 && hi<n && s[lo]==s[hi]){
//                 if(hi-lo+1>ans.size()){
//                     ans = s.substr(lo, hi-lo+1);
//                 }
//                 lo--;
//                 hi++;
//             }
//         }
        
        
        return ans;
    }
};