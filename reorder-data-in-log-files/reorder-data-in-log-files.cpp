class Solution {
public:
    static bool isAlpha(char c){
        return (c>='a'&& c<='z');
    }
    static bool comp(const string& a, const string& b){
        int sp1 = a.find(' ');
        int sp2 = b.find(' ');
        
        string a1 = a.substr(0, sp1);
        string b1 = b.substr(0, sp2);
        string a2 = a.substr(sp1+1);
        string b2 = b.substr(sp2+1);
        // cout<<a2<<"-"<<b2;//<endl;
        
                 // return a2<b2;
                
        if(a2==b2){
            // cout<<" aae"<<endl;
            return a1<b1;
        }
        else{
            // cout<<" aan"<<endl;
            return a2<b2;
        }
            
        
        
        // return 1;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> logsa, logsd;
        for(string& s:logs){
            int sp1 = s.find(' ');
            string a2 = s.substr(sp1+1);
            if(isAlpha(a2[0])){
                logsa.push_back(s);
            }
            else{
                logsd.push_back(s);
            }
        }
        sort(logsa.begin(), logsa.end(), comp);
        for(string& s:logsd){
            logsa.push_back(s);
        }
        return logsa;
    }
};