class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int start = -1;
        int mx = 0;
        
        for(int i=0;i<n;i++){
            int lo = i;
            int hi = i;
            
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                if(hi-lo+1>mx){
                    start = lo;
                    mx = hi-lo+1;
                }
                lo--;
                hi++;
            }
            
            lo = i;
            hi = i+1;
            
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                if(hi-lo+1>mx){
                    start = lo;
                    mx = hi-lo+1;
                }
                lo--;
                hi++;
            }
        }
                
        
        return s.substr(start, mx);
    }
};