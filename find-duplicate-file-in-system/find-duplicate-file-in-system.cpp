class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<string> tokens;
        
        for(string p:paths){
            size_t pos = p.find(' ');
            string path = p.substr(0, pos);
            string files = p.substr(pos+1, p.size()-pos-1);
            // cout<<path<<"->"<<endl;
            
            stringstream ss(files);
            vector<string> tokens;
            string token;
            while(getline(ss, token, ' '))
            {
                tokens.push_back(token);
                
                size_t b = token.find('(');
                string file = token.substr(0, b);
                string content = token.substr(b+1, token.size()-b-2);
                
                
                file = path+"/"+file;
                // cout<<file<<"->"<<content<<endl;
                m[content].push_back(file);
            }
        }
        vector<vector<string>> ans;
        for(auto p:m){
            if(p.second.size()>1){vector<string> tmp;
            for(string s:p.second){
                tmp.push_back(s);
            }
            ans.push_back(tmp);}
        }
        return ans;
    }
};