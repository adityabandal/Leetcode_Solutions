class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<int> s1,s2;
        for(int i=0;i<s.size();i++){
            s1.insert(s[i]);
            s2.insert(t[i]);
        }
        if(s1.size()!=s2.size()) return false;
        int x=0;
        while(x<s.size()){
            if(m.find(s[x])==m.end()){
                m[s[x]] = t[x];
            }
            else if(m[s[x]]!=t[x]){
                return false;
            }
            x++;
        }
        return true;
    }
};