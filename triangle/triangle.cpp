class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        for(int i=1;i<n;i++){
            t[i][0] += t[i-1][0];
            for(int j=1;j<t[i].size()-1;j++){
                t[i][j] += min(t[i-1][j-1], t[i-1][j]);
            }
            t[i][t[i].size()-1] += t[i-1][t[i-1].size()-1];
        }
        int ans = INT_MAX;
        for(int i=0;i<t[n-1].size();i++){
            ans = min(ans, t[n-1][i]);
        }
        return ans;
    }
};