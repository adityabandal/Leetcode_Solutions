#define ll long long
class Solution {
public:
    int minWastedSpace(vector<int>& p, vector<vector<int>>& boxes) {
        int M = 1e9+7;
        int n = p.size();
        sort(p.begin(), p.end());
        long long int ans = 1e10;
        vector<long long> psum(n+1, 0);
        
        psum[0] = 0;
        
        for(int i=0;i<n;i++){
            psum[i+1] = psum[i]+p[i];
        }
        for(auto& b:boxes){
            sort(b.begin(), b.end());
            long long w=0;
            long long prev = 0;
            for(int j=0;j<b.size() && prev<n;j++){
                auto it = upper_bound(p.begin(), p.end(), b[j]);
                long long idx = it-p.begin()-1;
                // cout<<idx<<" ";
                if(idx>=prev){
                    // cout<<psum[idx+1]-psum[prev]<<" "<<(idx-prev+1)*b[j];
                    w += ((idx-prev+1)*(ll)b[j])-(psum[idx+1]-psum[prev]);
                    prev = idx+1;
                }
                // cout<<endl;
            }
            if(prev == n)
            ans = min(ans, w);
            // cout<<endl;
        }
        return ans==1e10?-1:ans%M;
        
    }
};