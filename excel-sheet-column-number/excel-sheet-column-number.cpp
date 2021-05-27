class Solution {
public:
    int titleToNumber(string c) {
        int n = c.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = 26*ans + (c[i]-'A'+1);
        }
        return ans;
    }
};