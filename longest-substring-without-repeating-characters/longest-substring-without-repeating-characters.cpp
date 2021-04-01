class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        int ans = 1;
        unordered_map<char, int> m;
        m[s[0]] = 0;
        int begin = 0;;
        for(int i=1;i<n;i++){
            if(m.find(s[i])!=m.end()){
                begin = max(begin, m[s[i]]+1);
            }
            m[s[i]] = i;
            ans = max(ans, i-begin+1);
            cout<<ans<<endl;
        }
        return ans;
    }
};