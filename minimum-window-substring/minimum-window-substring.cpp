class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        unordered_map<char, int> st;
        for(char c:t){
            st[c]++;
        }
        
        unordered_map<char, int> m;
        int formed = 0;
        int i=0,j=0;
        string ans = "";
        int mn_len = INT_MAX;
        
        while(j<n){
            m[s[j]]++;
            
            if(st.count(s[j]) && m[s[j]]==st[s[j]]){
                // cout<<j<<endl;
                formed++;
            }
            
            if(formed == st.size()){
                while(!(st.count(s[i]) && m[s[i]]==st[s[i]])){
                    m[s[i]]--;
                    i++;
                }
                if(j-i+1 < mn_len){
                    mn_len = j-i+1;
                    ans = s.substr(i,mn_len);
                }
                m[s[i]]--;
                i++;
                formed--;
            }
            j++;
        }
        return ans;
    }
};