class Solution {
public:
    
    int maxScore(vector<int>& cp, int k) {
        
        int n = cp.size();
        int ans = 0;
        int sum = 0;
        for(int c:cp) sum+=c;
        
        int s = n-k;
        int curr = 0;
        for(int i=0;i<s;i++){
            curr+=cp[i];
        }
        ans = sum-curr;
        
        for(int i=s;i<n;i++){
            curr = curr + cp[i] - cp[i-s];
            ans = max(ans, sum-curr);
        }
        
        return ans;
    }
};