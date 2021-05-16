class Solution {
public:
    static bool comp(const string& s1,const string& s2){
        return s1.back()<s2.back();
    }
    string sortSentence(string s) {
        vector<string> tokens;
      
        // stringstream class check1
        stringstream check1(s);

        string intermediate;

        // Tokenizing w.r.t. space ' '
        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        
        sort(tokens.begin(), tokens.end(), comp);
            string ans = tokens[0].substr(0, tokens[0].size()-1);
        for(int i=1;i<tokens.size();i++){
            ans+=" ";
            ans+= tokens[i].substr(0, tokens[i].size()-1);
        }
        return ans;
        
    }
};