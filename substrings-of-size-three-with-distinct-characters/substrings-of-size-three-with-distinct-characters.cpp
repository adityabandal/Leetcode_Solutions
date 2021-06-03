class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int c = 0;
        int ans= 0;
        if(s.size() < 3) return 0;
        for(int i=0;i<3;i++){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']==2) c++;
            // cout<<c<<endl;
        }
        if(c==0) ans++;
        for(int i=3;i<s.size();i++){
            cnt[s[i-3]-'a']--;
            if(cnt[s[i-3]-'a']==1) c--;
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']==2) c++;
            if(c==0) ans++;
            // cout<<c<<endl;
        }
        return ans;
    }
};