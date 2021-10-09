class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mx = values[0];
        int ans = 0;
        
        for(int i=1;i<n;i++){
            ans = max(ans, mx+(values[i]+i)-(2*i));
            mx = max(mx, values[i]+i);
        }
        
        return ans;
    }
};