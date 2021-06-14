class Solution {
public:
    bool isPalindrome(string& s, int lo, int hi){
        while(lo<=hi){
            if(s[lo]!=s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
    
    vector<string> getValidPrefixes(string& s){
        int n = s.size();
        vector<string> ans;
        for(int i=n-1;i>=0;i--){
            if(isPalindrome(s,i,n-1)){
                ans.push_back(s.substr(0,i));
            }
        }
        return ans;
    }
    
    vector<string> getValidSufixes(string& s){
        int n = s.size();
        vector<string> ans;
        
        for(int i=0;i<n;i++){
            if(isPalindrome(s,0,i)){
                ans.push_back(s.substr(i+1));
            }
        }
        return ans;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        
        for(int i=0;i<n;i++){
            m[words[i]] = i;
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            string w = words[i];
            vector<string> pref = getValidPrefixes(w);
            vector<string> suff = getValidSufixes(w);
            // cout<<w<<"=>\n";
            string rev = w;
            reverse(rev.begin(), rev.end());
            if(m.find(rev)!=m.end()){
                if(m[rev]!=i){
                    ans.push_back({i,m[rev]});
                }
            }
            for(string& p:pref){
                reverse(p.begin(), p.end());
                if(m.find(p)!=m.end()){
                    ans.push_back({i,m[p]});
                }
            }
            for(string& s:suff){
                reverse(s.begin(), s.end());
                if(m.find(s)!=m.end()){
                    ans.push_back({m[s], i});
                }
            }
        }
        return ans;
    }
};