#define ll long long
class Solution {
public:
    int 
    long long wonderfulSubstrings(string s) {
        ll ans = 0;
        int M = 1e9+7;
        unordered_map<int, ll> m;
        int mask = 0;
        m[0] = 1;
        
        for(int i=0;i<s.size();i++){
            mask ^= 1<<(s[i]-'a');
            ans=(ans+m[mask]);
            for(int j=0;j<=9;j++){
                ans = (ans+m[mask ^ 1<<j]);
            }
            m[mask] = (m[mask]+1);
        }
        return ans;
    }
};