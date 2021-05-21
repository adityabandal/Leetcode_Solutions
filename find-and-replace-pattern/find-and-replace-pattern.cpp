class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string w:words){
            if(w.size()!=pattern.size()) continue;
            
            unordered_map<char, char> m1, m2;
            bool valid = true;
            for(int i=0;i<w.size();i++){
                char c = w[i], p = pattern[i];
                
                if(m1.count(c)+m2.count(p)==1) {
                    valid = false;
                    break;
                }
                else if(m1.count(c)+m2.count(p)==2) {
                    if(m1[c]!=p || m2[p]!=c){
                        valid = false;
                        break;
                    }
                }
                else{
                    m1[c]=p;
                    m2[p]=c;
                }
            }
            if(valid) ans.push_back(w);
        }
        return ans;
    }
};