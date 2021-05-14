class Solution {
public:
    string convertToTitle(int cn) {
        string ans = "";
        
        while(cn){
            cn--;
            ans += 'A'+cn%26;
            cn/=26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};