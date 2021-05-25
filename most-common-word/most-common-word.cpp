class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_set<string> b;
        int b_size = banned.size();
        for(int i=0;i<b_size;i++){
            b.insert(banned[i]);
        }
        
        int n = para.size();
        int start = 0;
        int mx = 0;
        string ans = "";
        unordered_map<string, int> m;
        for(int i=0;i<n;i++){
            char ch = para[i];
            if(ch>='A' && ch<='Z') {
                para[i] = 'a'+para[i]-'A';
                ch = para[i];
            }
            if(ch<'a' || ch>'z'){
                string str = para.substr(start, i-start);
                // cout<<str<<endl;
                if(str!="" && b.find(str)==b.end()){
                    m[str]++;
                    if(m[str]>mx){
                        mx = m[str];
                        ans = str;
                    }
                }
                start = i+1;
            }
        }
        string str = para.substr(start, n-start);
        if(str!="" && b.find(str)==b.end()){
            m[str]++;
            if(m[str]>mx){
                mx = m[str];
                ans = str;
            }
        }
        // cout<<para<<endl;
        return ans;
    }
};