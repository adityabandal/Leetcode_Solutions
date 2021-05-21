#define all(arr) arr.begin(), arr.end()
#define pb push_back
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(all(in));
        int n = in.size();
        if(n==0) return {};
        vector<vector<int>> ans;
        ans.pb(in[0]);
        
        for(int i=1;i<n;i++){
            if(ans.back()[1]>=in[i][0]){
                ans.back()[1] = max(ans.back()[1], in[i][1]);
            }
            else{
                ans.pb(in[i]);
            }
        }
        
        return ans;
    }
};