class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char, int> m;
        m['a'] = 1;
        m['e'] = 2;
        m['i'] = 3;
        m['o'] = 4;
        m['u'] = 5;
        int n = word.size();
        int curr = 1;
        int ans = 0;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(m[word[i]]>=m[word[i-1]]){
                if(m[word[i]]>m[word[i-1]]) cnt++;
                curr++;
            }
            else{
                if(cnt==5)
                    ans = max(ans, curr);
                curr = 1;
                cnt = 1;
            }
        }
        if(cnt==5)
                    ans = max(ans, curr);
        return ans;
    }
};