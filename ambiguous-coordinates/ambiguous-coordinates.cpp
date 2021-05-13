class Solution {
public:
    vector<string> dec(string s){
        if(s.size()==1) return {s};
        if(s.back()=='0'){ 
            if(s[0]!='0')
                return{s};
            else
                return {};
        }
        if(s[0]=='0'){
            if(stoi(s)==0 && s.size()>1) return {};
            s.insert(s.begin()+1, '.');
            return {s};
        }
        else{
            vector<string> ans;
            ans.push_back(s);
            int n = s.size();
            for(int i=1;i<n;i++){
                string tmp = s;
                if(stoi(s.substr(i))==0) break;
                tmp.insert(tmp.begin()+i, '.');
                ans.push_back(tmp);
            }
            return ans;
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1);
        s.pop_back();
        int n = s.size();
        vector<string> ans;
        for(int i=1;i<n;i++){
            string a = s.substr(0, i);
            string b = s.substr(i, n-i);
            // cout<<i<<"->"<<a<<" "<<b<<endl;
            vector<string> av = dec(a);
            vector<string> bv = dec(b);
            for(string x:av){ 
                // cout<<x<<" "; cout<<endl;
                x = "("+x+", ";
                for(string y:bv) {
                    // cout<<x<<" "; cout<<endl;
                    string tmp = x + y +")";
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};