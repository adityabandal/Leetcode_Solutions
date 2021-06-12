class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        
        stringstream ss(s);
        vector<string> tokens;
        string token;
        
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
            // cout<<token<<endl;
        }
        
        if(tokens.size()!=pattern.size()) return false;
        
        for(int i=0;i<tokens.size();i++){
            // cout<<i<<endl;
            char c = pattern[i];
            string x = tokens[i];
            if(m1.find(pattern[i])!=m1.end()){ // char found
                if(m2.find(tokens[i])!=m2.end()){   // string found
                    if(m1[c]!=x || m2[x]!=c) return false;
                }
                else{   //string not found
                    return false;
                }
            }
            else{   // char not found
                if(m2.find(tokens[i])!=m2.end()){   // string found
                    return false;
                }
                else{   //string not found
                    m1[c] = x;
                    m2[x] = c;
                }
            }
        }
        
        return true;;
    }
};