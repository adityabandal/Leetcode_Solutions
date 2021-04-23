class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int i = 0;
        int p0 = 0;
        int ans = 0;
        while(i<n){
            if(s[i]=='0'){
                i++;
                p0++;
            }
            else{
                int len = 0;
                while(i<n && s[i]=='1'){
                    i++;
                    len++;
                }
                int n0 = 0;
                while(i<n && s[i]=='0'){
                    i++;
                    n0++;
                }
                ans += min(p0, len) + min(n0, len);
                p0 = n0;
            }
        }
        return ans;
    }
};