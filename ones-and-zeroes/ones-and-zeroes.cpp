#define pi pair<int, int>
#define s second
#define f first
class Solution {
public:
    int dp[601][101][101];
    static bool comp(const string& a, const string& b){
        return a.size()<b.size();
    }
    int help(vector<pi>& v, int idx, int n, int m){
        if(n<0 || m<0 || idx>=v.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        else{
            int ans = 0;
            ans = help(v, idx+1, n, m);
            if(v[idx].f <= m && v[idx].s <=n){
                ans = max(ans,1+ help(v, idx+1, n-v[idx].s, m-v[idx].f));
            }
            return dp[idx][m][n] = ans;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // sort(strs.begin(), strs.end(), comp);
        // for(string s:strs){
        //     cout<<s<<endl;
        // }
        memset(dp, -1, sizeof(dp));
        int s = strs.size();
        int ans = 0;
        vector<pi> v;
        for(int i=0; i<s; i++){
            int o=0, z=0;
            for(char c:strs[i]){
                c=='1'?o++:z++;
            }
            v.push_back({z, o});
        }
        return help(v, 0, n, m);
    }
};