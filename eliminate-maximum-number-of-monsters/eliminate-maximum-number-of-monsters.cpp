class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> t;
        for(int i=0;i<n;i++){
            t.push_back((double)dist[i]/(double)speed[i]);
        }
        
        sort(t.begin(), t.end());
        int ans = 1;
        for(int i=1;i<n;i++){
            if(t[i]<=(double)i) return ans;
            ans++;
        }
        return ans;
    }
};