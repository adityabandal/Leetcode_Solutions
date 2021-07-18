class Solution {
public:
    int canBeTypedWords(string text, string b) {
        unordered_set<char> s;
        for(char c:b){
            s.insert(c);
        }
        
        stringstream ss(text);
        string token;
        int ans = 0;
        while(getline(ss, token, ' ')){
            bool p = true;
            for(char c:token){
                if(s.count(c)){
                    p = false;
                    break;
                }
            }
            if(p) ans++;
        }
        return ans;
    }
};