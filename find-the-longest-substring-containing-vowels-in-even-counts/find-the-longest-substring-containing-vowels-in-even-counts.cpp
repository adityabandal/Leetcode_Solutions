class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        m[0] = -1;
        
        int mask = 0;
        int ans = 0;
        string str = "aeiou";
        for(int i=0;i<s.size();i++){
            mask ^= ( 1<<(str.find(s[i])+1) )>>1;
            if(m.find(mask)==m.end()) m[mask] = i;
            ans = max(ans, i-m[mask]);
        }
        
        return ans;
    }
};